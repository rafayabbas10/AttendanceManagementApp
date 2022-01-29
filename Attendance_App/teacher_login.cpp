#include "teacher_login.h"
#include "ui_teacher_login.h"
#include "teacher_panel.h"
#include "ui_teacher_panel.h"

teacher_login::teacher_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacher_login)
{
    ui->setupUi(this);
    ui->tchrUsername->setPlaceholderText("Enter Your Username");
    ui->tchrPassword->setPlaceholderText("Enter Your Password");
    ui->tchrEmail->setPlaceholderText("Enter Your Email");
    ui->tchrPhone->setPlaceholderText("Enter Your Phone Number");
    ui->usernameLogin->setPlaceholderText("Enter Your Username");
    ui->passwordLogin->setPlaceholderText("Enter Your Password");

}

teacher_login::~teacher_login()
{
    delete ui;
}

void teacher_login::on_registerBtn_clicked()
{

        //retrieve data from input feilds
        QString name = ui->tchrName->text();
        QString username = ui->tchrUsername->text();
        QString password = ui->tchrPassword->text();
        QString email = ui->tchrEmail->text();
        QString phone = ui->tchrPhone->text();
        Teacher rgstr;
        if(rgstr.tchrRegister(name, username, password, email, phone) == 1){
            QMessageBox::information(this, "", "Records Updated");
        } else{
            QMessageBox::information(this, "", "Error: Unable to Register.");
        }

}


void teacher_login::on_loginBtn_clicked()
{
    username = ui->usernameLogin->text();
    password = ui->passwordLogin->text();


    Teacher lgn;
    if(lgn.tchrLogin(username, password) == 1){
        QMessageBox::information(this, "", "Sucess");
        lgn.setUsername(username);
        hide();
        sendUsername(username);
        tchrPanel = new teacherPanel(this);
        tchrPanel->show();
    } else {
        QMessageBox::information(this, "", "Login Failed");
    }

}

void teacher_login::sendUsername(QString user)
{
    emit Username(user);

}


