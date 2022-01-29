include "teacher_profilepage.h"
#include "ui_teacher_profilepage.h"

teacher_ProfilePage::teacher_ProfilePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacher_ProfilePage)
{
    ui->setupUi(this);
}

teacher_ProfilePage::~teacher_ProfilePage()
{
    delete ui;
}
