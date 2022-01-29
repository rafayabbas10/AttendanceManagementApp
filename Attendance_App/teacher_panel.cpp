#include "teacher_panel.h"
#include "ui_teacher_panel.h"

Teacher_Panel::Teacher_Panel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Teacher_Panel)
{
    ui->setupUi(this);
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", "MyConnection");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("attendance management");

    Teacher U;
    Username = U.getUsername();

    if(db.open()){
        QSqlQuery query(QSqlDatabase::database("MyConnection"));
        query.prepare(QString("SELECT * FROM teachers WHERE tchrUsername = :username"));

        query.bindValue(":username", Username);

        if(!query.exec()){


        } else{

            while(query.next()){

                QString nameDb = query.value(1).toString();
                QString idDb = query.value(0).toString();
                QString emailDb = query.value(4).toString();
                QString phoneDb = query.value(5).toString();

                Name = nameDb;
                ID = idDb;
                Email = emailDb;
                Phone = phoneDb;


            }
        }

    }
    ui->tchrName_lbl->setText(Name);

}

Teacher_Panel::~Teacher_Panel()
{
    delete ui;
}
