#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "HealthRecord.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(const QString& username, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddRecord();
    void onShowAnalysis();
    void onExportCSV();

    // NUEVO → para cambiar la vista cuando el admin elige un usuario
    void onUserChanged();

private:
    void loadRecords();
    void loadUsersForAdmin();   // NUEVO → cargar lista de usuarios si es admin

private:
    Ui::MainWindow *ui;
    QString currentUser;
    int currentUserId = -1;

    QVector<HealthRecord> records;

    bool isAdmin = false;       // NUEVO → marcar si es admin
};

#endif
