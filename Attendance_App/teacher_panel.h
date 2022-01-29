#ifndef TEACHER_PANEL_H
#define TEACHER_PANEL_H

#include <QDialog>

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "teacher.h"

namespace Ui {
class Teacher_Panel;
}

class Teacher_Panel : public QDialog, public Teacher
{
    Q_OBJECT

public:
    QString Username, Name, Email, Phone, ID;
    explicit Teacher_Panel(QWidget *parent = nullptr);
    ~Teacher_Panel();

private slots:
    void on_tchrName_lbl_linkActivated(const QString &link);

private:
    Ui::Teacher_Panel *ui;
    QSqlDatabase database;
};

#endif // TEACHER_PANEL_H
