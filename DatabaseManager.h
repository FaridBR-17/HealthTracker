#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include <QVector>
#include "HealthRecord.h"

class DatabaseManager {
public:
    static DatabaseManager& instance();

    bool createTables();
    bool registerUser(const QString& username, const QString& password);
    bool validateUser(const QString& username, const QString& password);

    
    bool addHealthRecord(int userId, double weight, int sys, int dia, double glucose);
    QVector<HealthRecord> getRecordsForUserId(int userId);

    
    QStringList getAllUsernames();
    int getUserId(const QString &username); 

private:
    DatabaseManager();
    QSqlDatabase db;
};

#endif
