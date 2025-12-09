#ifndef USER_H
#define USER_H

#include <QString>

class User {
public:
    int id;
    QString username;
    QString password;

    User();
    User(int id, const QString& username, const QString& password);
};

#endif

