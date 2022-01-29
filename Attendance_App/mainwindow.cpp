#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "teacher_login.h"
#include "ui_teacherpanel.h"
#include "studentpanel.h"
#include "ui_student_login.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_techer_clicked()
{
    hide();
    Teacher_login = new teachersPanel(this);
    Teacher_login -> show();
}


void MainWindow::on_pushButton_student_clicked()
{
    hide();
    studentpanel = new StudentPanel(this);
    studentpanel -> show();
}


void MainWindow::on_pushButton_admin_clicked()
{
    hide();
    admin_panel = new Admin_Panel(this);
    admin_panel ->show();
}

