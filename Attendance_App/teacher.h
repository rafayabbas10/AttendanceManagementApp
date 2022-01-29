#ifndef TEACHER_H
#define TEACHER_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QLabel>
#include <QMessageBox>
#include "teacherspanel.h"

class Teacher: public QLabel
{
        Q_OBJECT
public:
    explicit Teacher(QWidget *parent = 0);
    QString tchrID, tchrName, tchrUsername, tchrPassword, tchrEmail, tchrPhone;
    int tchrRegister(QString Name, QString Username, QString Password, QString Email, QString Phone);
    int tchrLogin(QString Username, QString Password);
    void setUsername(QString user);
    QString getUsername();
    int markAttendance(QString clsID, bool atdPresence, QString stdRollNo, QString crsCode, int tchrID);

    void nameOut();

signals:

private slots:
    void setData();


private:


};

#endif // TEACHER_H
