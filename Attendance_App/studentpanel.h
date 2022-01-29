#ifndef STUDENTPANEL_H
#define STUDENTPANEL_H

#include <QDialog>
#include "student.h"

namespace Ui {
class StudentPanel;
}

class StudentPanel : public QDialog
{
    Q_OBJECT

public:
    explicit StudentPanel(QWidget *parent = nullptr);
    ~StudentPanel();

private slots:
    void on_loginBtn_clicked();

    void on_showCourses_clicked();

    void on_Courses_activated(const QModelIndex &index);

    void on_selectTeacher_activated(const QModelIndex &index);

private:
    Ui::StudentPanel *ui;
    QString stdRollNo, stdName, stdUsername,
            stdPassword, stdEmail, stdPhone,
            stdBatch, crsCode, tchrName, tchrID;

};

#endif // STUDENTPANEL_H
