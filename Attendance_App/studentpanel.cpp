#include "studentpanel.h"
#include "ui_studentpanel.h"

StudentPanel::StudentPanel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentPanel)
{
    ui->setupUi(this);
}

StudentPanel::~StudentPanel()
{
    delete ui;
}

void StudentPanel::on_loginBtn_clicked()
{
    stdUsername = ui->usernameLogin->text();
    stdPassword = ui->passwordLogin->text();

    Student std;
    if(std.stdLogin(stdUsername, stdPassword) == 1){
        QSqlDatabase db;
        db = QSqlDatabase::addDatabase("QMYSQL", "MyConnection");
        db.setHostName("localhost");
        db.setUserName("root");
        db.setPassword("");
        db.setDatabaseName("attendance management");

        if(db.open()){
            QSqlQuery query(QSqlDatabase::database("MyConnection"));
            query.prepare(QString("SELECT * FROM students WHERE stdUsername = :stdUsername"));

            query.bindValue(":stdUsername", stdUsername);

            if(!query.exec()){


            } else{

                while(query.next()){
\
                    stdName = query.value(1).toString();
                    stdRollNo = query.value(0).toString();
                    stdEmail = query.value(6).toString();
                    stdPhone = query.value(7).toString();
                    stdBatch = query.value(2).toString();
                }
            }

        } else {
            QMessageBox::information(this, "", "Login Failed.");
        }
        ui->stdName_lbl->setText(stdName);
        ui->stdRollNo_lbl->setText(stdRollNo);
        ui->stdEmail_lbl->setText(stdEmail);
        ui->stdPhone_lbl->setText(stdPhone);
        ui->stdBatch_lbl->setText(stdBatch);

    }

}


void StudentPanel::on_showCourses_clicked()
{
    QSqlDatabase db3;
    db3 = QSqlDatabase::addDatabase("QMYSQL", "MyConnection");
    db3.setHostName("localhost");
    db3.setUserName("root");
    db3.setPassword("");
    db3.setDatabaseName("attendance management");

    QSqlQuery qery(QSqlDatabase::database("MyConnection"));
    qery.prepare("SELECT crsCode FROM student_has_a_course WHERE stdRollNo = :stdRollNo");
    qery.bindValue(":stdRollNo", stdRollNo);

    if(qery.exec()){
       QSqlQueryModel *modal =new QSqlQueryModel;
       modal->setQuery(qery);
       ui->Courses->setModel(modal);


    } else {
        QMessageBox::information(this, "", "Database Connection Failed");
    }
}


void StudentPanel::on_Courses_activated(const QModelIndex &index)
{
    crsCode = ui->Courses->model()->data(index).toString();
    QSqlDatabase db4;
    db4 = QSqlDatabase::addDatabase("QMYSQL", "Connection");
    db4.setHostName("localhost");
    db4.setUserName("root");
    db4.setPassword("");
    db4.setDatabaseName("attendance management");
    if(db4.open()){
        QSqlQuery qery3(QSqlDatabase::database("Connection"));


        qery3.prepare("SELECT tchrName FROM teacher_has_a_course WHERE crsCode = :crsCode");
        qery3.bindValue(":crsCode", crsCode);
        if(qery3.exec()){
            QSqlQueryModel *modal = new QSqlQueryModel;
            modal->setQuery(qery3);
            ui->selectTeacher->setModel(modal);
        } else {
            QMessageBox::information(this, "", "Database Connection Failed.");
        }


    } else {
        QMessageBox::information(this, "", "Database Failed.");
    }

}


void StudentPanel::on_selectTeacher_activated(const QModelIndex &index)
{
    tchrName = ui->selectTeacher->model()->data(index).toString();
    QSqlDatabase db4;
    db4 = QSqlDatabase::addDatabase("QMYSQL", "Connection");
    db4.setHostName("localhost");
    db4.setUserName("root");
    db4.setPassword("");
    db4.setDatabaseName("attendance management");
    if(db4.open()){
        QSqlQuery qry(QSqlDatabase::database("Connection"));
        qry.prepare("SELECT * FROM teachers WHERE tchrName = :tchrName");
        qry.bindValue(":tchrName", tchrName);
        if(qry.exec()){
            while (qry.next()) {
                tchrID = qry.value(0).toString();
            }
        } else {
            QMessageBox::information(this, "", "qry did not exec()");
        }
        int percentage;
        Student std;
        percentage = std.attPercentage(stdRollNo, crsCode, tchrID);
        ui->Percentage->setText(QString::number(percentage) + "%");
        if(percentage < 70){
            ui->Percentage->setStyleSheet("background-color: #ff6363;border-radius:10px;border:none;");
        } else if(percentage > 70 && percentage < 85){
            ui->Percentage->setStyleSheet("background-color: #ffbb63;border-radius:10px;border:none;");
        } else if(percentage > 85){
            ui->Percentage->setStyleSheet("background-color: #80ff63;border-radius:10px;border:none;");
        }
        qry.prepare("SELECT crsName FROM course WHERE crsCode = :crsCode");
        qry.bindValue(":crsCode", crsCode);
        if (qry.exec()){
            while (qry.next()) {
                ui->crsName->setText(qry.value(0).toString());
            }
        } else {
            QMessageBox::information(this, "", qry.value(0).toString());
        }
        qry.prepare("SELECT * FROM attendance WHERE stdRollNo = :stdRollNo AND crsCode = :crsCode");
        qry.bindValue(":stdRollNo", stdRollNo);
        qry.bindValue(":crsCode", crsCode);
        if (qry.exec()){
            QSqlQueryModel *modal= new QSqlQueryModel;
            modal->setQuery(qry);
            ui->Attendance->setModel(modal);
        }
    } else {
        QMessageBox::information(this, "", "Database Connection Lost.");
    }

}



