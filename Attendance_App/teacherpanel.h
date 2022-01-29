#ifndef TEACHERPANEL_H
#define TEACHERPANEL_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "teacher.h"


namespace Ui {
class teacherPanel;
}

class teacherPanel : public QDialog
{
    Q_OBJECT

public:
    void setUiElements();

    explicit teacherPanel(QWidget *parent = nullptr);
    ~teacherPanel();

public slots:



private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_showCourses_clicked();

    void on_listView_activated(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_loginBtn_clicked();

    void on_allClasses_activated(const QModelIndex &index);

private:
    QString strTID, crsCode;
    int tchrID, clsID;
    QString tchrName, tchrUsername, tchrPassword, tchrEmail, tchrPhone;
    Ui::teacherPanel *ui;
    QSqlDatabase database;

};

#endif // TEACHERPANEL_H
