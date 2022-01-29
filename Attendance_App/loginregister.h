#ifndef LOGINREGISTER_H
#define LOGINREGISTER_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

class LoginRegister:public QWidget
{
public:
    void userRegister(QString username, QString password, QString email, QString phone, QString dbName);
    int userLogin(QString username, QString password, QString dbName);
};

#endif // LOGINREGISTER_H
