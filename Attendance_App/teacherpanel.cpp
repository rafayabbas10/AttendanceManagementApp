#include "teacherpanel.h"
#include "ui_teacherpanel.h"

teacherPanel::teacherPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::teacherPanel)
{

    ui->setupUi(this);
    ui->usernameLogin->setPlaceholderText("Enter Your Username");
    ui->passwordLogin->setPlaceholderText("Enter Your Password");
    ui->clsID1->setPlaceholderText("Enter 4 digit Class ID e.g XXXX");

}

teacherPanel::~teacherPanel()
{
    delete ui;
}




void teacherPanel::on_pushButton_clicked()
{

}

void teacherPanel::on_pushButton_2_clicked()
{

}


void teacherPanel::on_showCourses_clicked()
{
    QSqlDatabase db3;
    db3 = QSqlDatabase::addDatabase("QMYSQL", "MyConnection");
    db3.setHostName("localhost");
    db3.setUserName("root");
    db3.setPassword("");
    db3.setDatabaseName("attendance management");

    QSqlQueryModel *modal =new QSqlQueryModel;


    QSqlQuery qery(QSqlDatabase::database("MyConnection"));
    qery.prepare("SELECT crsCode FROM teacher_has_a_course WHERE tchrID = :tchrID");
    qery.bindValue(":tchrID", strTID);

    if(qery.exec()){
       modal->setQuery(qery);
       ui->listView->setModel(modal);


    } else {
        QMessageBox::information(this, "", "Database Connection Failed");
    }


}


void teacherPanel::on_listView_activated(const QModelIndex &index)
{
    crsCode = ui->listView->model()->data(index).toString();
    QSqlQueryModel *modal2 =new QSqlQueryModel;
    QSqlQueryModel *modal3 =new QSqlQueryModel;

    QSqlDatabase db4;
    db4 = QSqlDatabase::addDatabase("QMYSQL", "Connection");
    db4.setHostName("localhost");
    db4.setUserName("root");
    db4.setPassword("");
    db4.setDatabaseName("attendance management");
    if(db4.open()){
        QSqlQuery qery3(QSqlDatabase::database("Connection"));


        qery3.prepare("SELECT * FROM course WHERE crsCode = :crsCode");
        qery3.bindValue(":crsCode", crsCode);

        if(qery3.exec()){
            while (qery3.next()){
                QString crsName = qery3.value(1).toString();
                ui->crsName->setText(crsName);
            }
        } else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }

        qery3.prepare("SELECT * FROM student_has_a_course WHERE crsCode = :crsCode");
        qery3.bindValue(":crsCode", crsCode);
        if(qery3.exec()){
            while (qery3.next()){
                modal2->setQuery(qery3);
                ui->EnrolledStudents_tbl->setModel(modal2);
            }
        } else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }
        qery3.prepare("SELECT * FROM class WHERE crsCode = :crsCode");
        qery3.bindValue(":crsCode", crsCode);
        if(qery3.exec()){
            while (qery3.next()){
                modal3->setQuery(qery3);
                ui->allClasses->setModel(modal3);
            }
        } else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }

    } else {
        QMessageBox::information(this, "", "Database Failed.");
    }

}

void teacherPanel::on_allClasses_activated(const QModelIndex &index)
{

    QString val=ui->att->model()->data(index).toString();
    QSqlQueryModel *modal =new QSqlQueryModel;
    QSqlDatabase d;
    d = QSqlDatabase::addDatabase("QMYSQL", "Connection");
    d.setHostName("localhost");
    d.setUserName("root");
    d.setPassword("");
    d.setDatabaseName("attendance management");

    if(d.open()){

        QSqlQuery qry(QSqlDatabase::database("Connection"));
        qry.prepare("SELECT * FROM attendance WHERE clsID = :clsID");
        qry.bindValue(":cldID", val);
        if(qry.exec()){
            modal->setQuery(qry);
            ui->att->setModel(modal);
        }else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }
    } else {
        QMessageBox::information(this, "", "Database Failed.");
    }

}


void teacherPanel::on_pushButton_3_clicked()
{
    QString date = QDate::currentDate().toString();
    QString time = QTime::currentTime().toString();
    QString clsID1 = ui->clsID1->text();
    clsID = clsID1.toInt();
    QSqlQueryModel *modal =new QSqlQueryModel;
    QSqlQueryModel *modal2 =new QSqlQueryModel;
    QSqlDatabase db5;
    db5 = QSqlDatabase::addDatabase("QMYSQL", "Connect");
    db5.setHostName("localhost");
    db5.setUserName("root");
    db5.setPassword("");
    db5.setDatabaseName("attendance management");
    if(db5.open()){
        QSqlQuery qry2(QSqlDatabase::database("Connect"));
        qry2.prepare("INSERT INTO class (clsID, clsDate, clsTime, tchrID, crsCode)"
                     "VALUES (:clsID, :clsDate, :clsTime, :tchrID, :crsCode)");
        qry2.bindValue(":clsID", clsID);
        qry2.bindValue(":clsDate", date);
        qry2.bindValue(":clsTime", time);
        qry2.bindValue(":tchrID", tchrID);
        qry2.bindValue(":crsCode", crsCode);

        if(qry2.exec()){
            ui->info->setText("Records Updated");
            ui->time->setText(time);
            ui->date->setText(date);
            ui->clsID->setText(clsID1);

        } else {
            QMessageBox::information(this, "", "Can't create class."+ crsCode+ QString::number(tchrID)+date+time);
        }
        qry2.prepare("SELECT * FROM student_has_a_course WHERE crsCode = :crsCode");
        qry2.bindValue(":crsCode", crsCode);
        if(qry2.exec()){
            while (qry2.next()){
                modal->setQuery(qry2);
                ui->att->setModel(modal);
            }
        } else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }
        qry2.prepare("SELECT * FROM student_has_a_course WHERE crsCode = :crsCode");
        qry2.bindValue(":crsCode", crsCode);
        if(qry2.exec()){
            while (qry2.next()){
                modal2->setQuery(qry2);
                ui->EnrolledStudents_tbl->setModel(modal2);
            }
        } else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }

    }else{
        QMessageBox::information(this, "", "Database Connection Failed");
    }


}


void teacherPanel::on_loginBtn_clicked()
{
    tchrUsername = ui->usernameLogin->text();
    tchrPassword = ui->passwordLogin->text();


    Teacher lgn;
    if(lgn.tchrLogin(tchrUsername, tchrPassword) == 1){
        QMessageBox::information(this, "", "Sucess");

        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL", "MyConnection");
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("attendance management");

        QString nameDb;
        int idDb;
        QString emailDb;
        QString phoneDb;

        if(db.open()){
            QSqlQuery query(QSqlDatabase::database("MyConnection"));
            query.prepare(QString("SELECT * FROM teachers WHERE tchrUsername = :username"));

            query.bindValue(":username", tchrUsername);

            if(!query.exec()){


            } else{

                while(query.next()){

                    nameDb = query.value(1).toString();
                    idDb = query.value(0).toInt();
                    emailDb = query.value(4).toString();
                    phoneDb = query.value(5).toString();

                    tchrName = nameDb;
                    tchrID = idDb;
                    tchrEmail = emailDb;
                    tchrPhone = phoneDb;
                }
            }

        } else {
            QMessageBox::information(this, "", "Database not connected.");
        }
        strTID = QString::number(tchrID);
        ui->tchrName_lbl->setText(tchrName);
        ui->tchrID_lbl->setText(strTID);
        ui->tchrEmail_lbl->setText(tchrEmail);
        ui->tchrPhone_lbl->setText(tchrPhone);


    } else {
        QMessageBox::information(this, "", "Login Failed");
    }

}

