#ifndef STUDENT_H
#define STUDENT_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


class Student:public QWidget
{
public:
    void stdRegister(QString stdRollNo, QString stdName, QString stdBatch, QString stdUsername,
                     QString stdPassword, QString stdEmail, QString stdPhone, QString stdSection);
    int stdLogin(QString stdUsername, QString stdPassword);
    int attPercentage(QString stdRollNo, QString crsCode, QString tchrID);

};

#endif // STUDENT_H
