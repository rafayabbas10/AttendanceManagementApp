#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "teacherspanel.h"
#include "studentpanel.h"
#include "admin_panel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_techer_clicked();

    void on_pushButton_student_clicked();

    void on_pushButton_admin_clicked();

private:
    Ui::MainWindow *ui;
    teachersPanel *Teacher_login;
    StudentPanel *studentpanel;
    Admin_Panel *admin_panel;
};
#endif // MAINWINDOW_H
