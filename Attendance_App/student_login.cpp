#include "student_login.h"
#include "ui_student_login.h"

student_login::student_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_login)
{
    ui->setupUi(this);
}

student_login::~student_login()
{
    delete ui;
}






void student_login::on_loginBtn_clicked()
{
    QString stdUsername = ui->usernameLogin->text();
    QString stdPassword = ui->passwordLogin->text();

    Student login;
    login.stdLogin(stdUsername, stdPassword);
}


void student_login::on_registerBtn_clicked()
{
    QString stdUsername = ui->stdUsername->text();
    QString stdRollNo = ui->stdRollNo->text();
    QString stdName = ui->stdName->text();
    QString stdBatch = ui->stdBatch->text();
    QString stdPassword = ui->stdPassword->text();
    QString stdEmail = ui->stdEmail->text();
    QString stdPhone = ui->stdPhone->text();
    QString stdSection = ui->stdSection->text();

    Student rgstr;
    rgstr.stdRegister( stdRollNo, stdName, stdBatch, stdUsername,
                     stdPassword, stdEmail, stdPhone, stdSection);

}

