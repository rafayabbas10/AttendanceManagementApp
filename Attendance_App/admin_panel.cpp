#include "admin_panel.h"
#include "ui_admin_panel.h"

Admin_Panel::Admin_Panel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Admin_Panel)
{
    ui->setupUi(this);
}

Admin_Panel::~Admin_Panel()
{
    delete ui;
}



void Admin_Panel::on_Enroll_clicked()
{
    QString crsCode = ui->crsCode->text();
    QString stdRollNo = ui->stdRollNo->text();
    QString stdName = ui->stdName->text();

    Admin enroll;
    enroll.EnrollStudent(crsCode, stdRollNo, stdName);
}

void Admin_Panel::on_pushButton_clicked()
{
    QString crsCode = ui->crsCode->text();
    QString stdRollNo = ui->stdRollNo->text();
    QString stdName = ui->stdName->text();

    Admin enroll;
    enroll.EnrollStudent(crsCode, stdRollNo, stdName);
}


void Admin_Panel::on_Assign_clicked()
{
    Admin assign;
    if(assign.AssignTeacher(ui->crsCode_2->text(), ui->tchrId->text(), ui->tchrName_2->text()) == 1){
        ui->label_13->setText("Records Updated");
    } else {
        ui->label_13->setText("Records Not Updated");
    }
}


void Admin_Panel::on_searchTeacher_clicked()
{
}

