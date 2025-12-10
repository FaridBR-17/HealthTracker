#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DatabaseManager.h"
#include "HealthAnalyzer.h"
#include "CSVExporter.h"

#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(const QString& username, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      currentUser(username)
{
    ui->setupUi(this);

    setWindowTitle("Bienvenido " + username);

    
    isAdmin = (username == "admin");

    
    currentUserId = DatabaseManager::instance().getUserId(username);

    
    if (isAdmin) {
        loadUsersForAdmin();
        connect(ui->userSelector, &QComboBox::currentTextChanged,
                this, &MainWindow::onUserChanged);
    } else {
        ui->userSelector->setVisible(false);
    }

    
    loadRecords();

    
    connect(ui->btnAdd, &QPushButton::clicked, this, &MainWindow::onAddRecord);
    connect(ui->btnAnalysis, &QPushButton::clicked, this, &MainWindow::onShowAnalysis);
    connect(ui->btnExport, &QPushButton::clicked, this, &MainWindow::onExportCSV);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadUsersForAdmin() {
    QStringList users = DatabaseManager::instance().getAllUsernames();
    ui->userSelector->clear();
    ui->userSelector->addItems(users);

    
    ui->userSelector->setCurrentText("admin");
}

void MainWindow::onUserChanged() {
    QString selected = ui->userSelector->currentText();
    currentUserId = DatabaseManager::instance().getUserId(selected);
    loadRecords();
}

void MainWindow::loadRecords() {
    records = DatabaseManager::instance().getRecordsForUserId(currentUserId);

    ui->listWidget->clear();

    for (const auto &r : records) {
        ui->listWidget->addItem(
            r.timestamp() +
            QString(" | Peso: %1 | %2/%3 | Glucosa: %4")
            .arg(r.weight())
            .arg(r.systolic())
            .arg(r.diastolic())
            .arg(r.glucose())
        );
    }
}

void MainWindow::onAddRecord() {
    double w = ui->txtWeight->text().toDouble();
    int s = ui->txtSys->text().toInt();
    int d = ui->txtDia->text().toInt();
    double g = ui->txtGlucose->text().toDouble();

    if (!DatabaseManager::instance().addHealthRecord(currentUserId, w, s, d, g)) {
        QMessageBox::warning(this, "Error", "No se pudo agregar el registro.");
        return;
    }

    QMessageBox::information(this, "OK", "Registro agregado.");
    loadRecords();
}

void MainWindow::onShowAnalysis() {
    if (records.isEmpty()) {
        QMessageBox::information(this, "Análisis", "No hay datos suficientes.");
        return;
    }

    double avgW = HealthAnalyzer::averageWeight(records);
    double avgS = HealthAnalyzer::averageSystolic(records);
    double avgD = HealthAnalyzer::averageDiastolic(records);
    double avgG = HealthAnalyzer::averageGlucose(records);

    QString summary =
        QString("Promedios:\n\n")
        + "Peso: " + QString::number(avgW) + "\n"
        + "Sistólica: " + QString::number(avgS) + "\n"
        + "Diastólica: " + QString::number(avgD) + "\n"
        + "Glucosa: " + QString::number(avgG) + "\n\n"
        + "Riesgos:\n" + HealthAnalyzer::riskSummary(records);

    QMessageBox::information(this, "Análisis de Salud", summary);
}

void MainWindow::onExportCSV() {
    if (records.isEmpty()) {
        QMessageBox::information(this, "Exportar", "No hay registros.");
        return;
    }

    QString path = QFileDialog::getSaveFileName(
        this, "Guardar CSV", "historial.csv", "CSV (*.csv)");

    if (path.isEmpty())
        return;

    if (CSVExporter::exportRecords(path, records)) {
        QMessageBox::information(this, "Exportar", "Archivo guardado correctamente.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo guardar el archivo.");
    }
}
