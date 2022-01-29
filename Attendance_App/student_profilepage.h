#ifndef STUDENT_PROFILEPAGE_H
#define STUDENT_PROFILEPAGE_H

#include <QDialog>
#include "student.h"

namespace Ui {
class student_ProfilePage: public QWidget, public Student;
}

class student_ProfilePage : public QDialog
{
    Q_OBJECT

public:
    explicit student_ProfilePage(QWidget *parent = nullptr);
    ~student_ProfilePage();

private:
    Ui::student_ProfilePage *ui;
};

#endif // STUDENT_PROFILEPAGE_H
