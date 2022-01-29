#ifndef ADMIN_PANEL_H
#define ADMIN_PANEL_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class Admin_Panel;
}

class Admin_Panel : public QDialog
{
    Q_OBJECT

public:
    explicit Admin_Panel(QWidget *parent = nullptr);
    ~Admin_Panel();

private slots:
    void on_pushButton_clicked();

    void on_Enroll_clicked();

    void on_Assign_clicked();

    void on_searchTeacher_clicked();


private:
    Ui::Admin_Panel *ui;
};

#endif // ADMIN_PANEL_H
