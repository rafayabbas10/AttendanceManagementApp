#ifndef STUDENT_LOGIN_H
#define STUDENT_LOGIN_H

#include <QDialog>
#include "student.h"

namespace Ui {
class student_login;
}

class student_login :public QDialog
{
    Q_OBJECT

public:
    explicit student_login(QWidget *parent = nullptr);
    ~student_login();

private slots:
    void on_registerBtn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::student_login *ui;
};

#endif // STUDENT_LOGIN_H
