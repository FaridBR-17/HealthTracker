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

    void onUserChanged();

private:
    void loadRecords();
    void loadUsersForAdmin();   

private:
    Ui::MainWindow *ui;
    QString currentUser;
    int currentUserId = -1;

    QVector<HealthRecord> records;

    bool isAdmin = false;       
};

#endif
