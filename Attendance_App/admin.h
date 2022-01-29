#ifndef ADMIN_H
#define ADMIN_H

#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "admin_panel.h"
#include "ui_admin_panel.h"
#include "student.h"

namespace Ui {
class Admin;
}

class Admin:public QWidget
{
public:
    void EnrollStudent(QString crsCode, QString stdRollNo, QString stdName);
    int AssignTeacher(QString crsCode, QString tchrId, QString tchrName);
    //std::list SearchTeacher(QString tchrId);

private slots:
    void on_registerBtn_clicked();

private:
    Ui::Admin_Panel *ui;
};

#endif // ADMIN_H
