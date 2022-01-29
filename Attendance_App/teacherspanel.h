#ifndef TEACHERSPANEL_H
#define TEACHERSPANEL_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "teacher.h"

namespace Ui {
class teachersPanel;
}

class teachersPanel : public QDialog
{
    Q_OBJECT

public:
    explicit teachersPanel(QWidget *parent = nullptr);
    ~teachersPanel();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_showCourses_clicked();

    void on_listView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_loginBtn_clicked();

    void on_allClasses_activated(const QModelIndex &index);

    void on_att_activated(const QModelIndex &index);

    void on_present_clicked();

    void on_absent_clicked();

private:
    QString strTID, crsCode, clsID;
    int tchrID;
    QString tchrName, tchrUsername, tchrPassword, tchrEmail, tchrPhone;
    Ui::teachersPanel *ui;
    QSqlDatabase database;
};

#endif // TEACHERSPANEL_H
