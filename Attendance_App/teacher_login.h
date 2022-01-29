#ifndef TEACHER_LOGIN_H
#define TEACHER_LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "teacher.h"
#include "teacherpanel.h"



namespace Ui {
class teacher_login;
}

class teacher_login : public QDialog
{
    Q_OBJECT

public:
    QString tchrUsername, tchrPassword;
    explicit teacher_login(QWidget *parent = nullptr);
    ~teacher_login();

    QString username, password;
    void sendUsername(QString);

signals:
    void Username(QString);

private slots:
    void on_registerBtn_clicked();

    void on_loginBtn_clicked();


private:
    Ui::teacher_login *ui;
    Teacher *teacher;
    QSqlDatabase database;
    teacherPanel *tchrPanel;
};

#endif // TEACHER_LOGIN_H
