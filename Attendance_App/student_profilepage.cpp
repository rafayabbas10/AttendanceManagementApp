#include "student_profilepage.h"
#include "ui_student_profilepage.h"

student_ProfilePage::student_ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::student_ProfilePage)
{
    ui->setupUi(this);
}

student_ProfilePage::~student_ProfilePage()
{
    delete ui;
}
