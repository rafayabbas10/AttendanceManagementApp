#ifndef TEACHER_PROFILEPAGE_H
#define TEACHER_PROFILEPAGE_H

#include <QDialog>

namespace Ui {
class teacher_ProfilePage;
}

class teacher_ProfilePage : public QDialog
{
    Q_OBJECT

public:
    explicit teacher_ProfilePage(QWidget *parent = nullptr);
    ~teacher_ProfilePage();

private:
    Ui::teacher_ProfilePage *ui;
};

#endif // TEACHER_PROFILEPAGE_H
