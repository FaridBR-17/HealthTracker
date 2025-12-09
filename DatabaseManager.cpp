#include "DatabaseManager.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QDateTime>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("health.db");

    if (!db.open()) {
        qDebug() << "No se pudo abrir la base de datos.";
    }
}

DatabaseManager& DatabaseManager::instance() {
    static DatabaseManager inst;
    return inst;
}

bool DatabaseManager::createTables() {
    QSqlQuery q;

    bool ok1 = q.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "username TEXT UNIQUE,"
        "password TEXT)"
    );
    if (!ok1) {
        qDebug() << "Error creando users:" << q.lastError().text();
        return false;
    }

    bool ok2 = q.exec(
        "CREATE TABLE IF NOT EXISTS health_records ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
        "user_id INTEGER,"
        "timestamp TEXT,"
        "weight REAL,"
        "systolic INTEGER,"
        "diastolic INTEGER,"
        "glucose REAL,"
        "FOREIGN KEY(user_id) REFERENCES users(id))"
    );
    if (!ok2) {
        qDebug() << "Error creando health_records:" << q.lastError().text();
        return false;
    }

    // crear admin si no existe
    QSqlQuery check;
    check.prepare("SELECT id FROM users WHERE username = 'admin'");
    check.exec();
    if (!check.next()) {
        QSqlQuery insert;
        insert.prepare("INSERT INTO users (username, password) VALUES ('admin', 'admin')");
        if (!insert.exec()) {
            qDebug() << "Error creando admin:" << insert.lastError().text();
        } else {
            qDebug() << "Usuario admin creado (admin/admin).";
        }
    }
    return true;
}

bool DatabaseManager::registerUser(const QString& username, const QString& password) {
    QSqlQuery q;
    q.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
    q.addBindValue(username);
    q.addBindValue(password);
    if (!q.exec()) {
        qDebug() << "registerUser error:" << q.lastError().text();
        return false;
    }
    return true;
}

bool DatabaseManager::validateUser(const QString& username, const QString& password) {
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE username = ? AND password = ?");
    q.addBindValue(username);
    q.addBindValue(password);
    if (!q.exec()) {
        qDebug() << "validateUser error:" << q.lastError().text();
        return false;
    }
    return q.next();
}

bool DatabaseManager::addHealthRecord(int userId, double weight, int sys, int dia, double glucose) {
    QSqlQuery q;
    q.prepare("INSERT INTO health_records (user_id, timestamp, weight, systolic, diastolic, glucose) "
              "VALUES (?, ?, ?, ?, ?, ?)");
    q.addBindValue(userId);
    q.addBindValue(QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss"));
    if (weight < 0) q.addBindValue(QVariant()); else q.addBindValue(weight);
    if (sys < 0) q.addBindValue(QVariant()); else q.addBindValue(sys);
    if (dia < 0) q.addBindValue(QVariant()); else q.addBindValue(dia);
    if (glucose < 0) q.addBindValue(QVariant()); else q.addBindValue(glucose);

    if (!q.exec()) {
        qDebug() << "addHealthRecord error:" << q.lastError().text();
        return false;
    }
    return true;
}

QVector<HealthRecord> DatabaseManager::getRecordsForUserId(int userId) {
    QVector<HealthRecord> list;
    QSqlQuery q;
    q.prepare("SELECT id, user_id, timestamp, weight, systolic, diastolic, glucose "
              "FROM health_records WHERE user_id = ? ORDER BY timestamp DESC");
    q.addBindValue(userId);
    if (!q.exec()) {
        qDebug() << "getRecordsForUserId error:" << q.lastError().text();
        return list;
    }

    while (q.next()) {
        int id = q.value(0).toInt();
        int uid = q.value(1).toInt();
        QString ts = q.value(2).toString();
        double w = q.value(3).isNull() ? -1.0 : q.value(3).toDouble();
        int s = q.value(4).isNull() ? -1 : q.value(4).toInt();
        int d = q.value(5).isNull() ? -1 : q.value(5).toInt();
        double g = q.value(6).isNull() ? -1.0 : q.value(6).toDouble();

        list.append(HealthRecord(id, uid, ts, w, s, d, g));
    }
    return list;
}

QStringList DatabaseManager::getAllUsernames() {
    QStringList res;
    QSqlQuery q("SELECT username FROM users ORDER BY username");
    while (q.next()) res << q.value(0).toString();
    return res;
}

int DatabaseManager::getUserId(const QString &username) {
    QSqlQuery q;
    q.prepare("SELECT id FROM users WHERE username = ?");
    q.addBindValue(username);
    if (!q.exec()) {
        qDebug() << "getUserId error:" << q.lastError().text();
        return -1;
    }
    if (q.next()) return q.value(0).toInt();
    return -1;
}
