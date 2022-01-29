#include "admin.h"

void Admin::EnrollStudent(QString crsCode, QString stdRollNo, QString stdName)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("attendance management");

    if (database.open()){
    // run our insert query
        QSqlQuery qry;
        qry.prepare("INSERT INTO student_has_a_course (crsCode, stdRollNo, stdName)"
                    "VALUES (:crsCode, :stdRollNo, :stdName)");

        qry.bindValue(":stdRollNo", stdRollNo);
        qry.bindValue(":crsCode", crsCode);
        qry.bindValue(":stdName", stdName);

        if(qry.exec()){
            QMessageBox::information(this, "", "Records Updated");

        } else {
            QMessageBox::information(this, "", "Database Connection Lost");
       }
    }


}

int Admin::AssignTeacher(QString crsCode, QString tchrId, QString tchrName)
{
    int state=0;
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName("attendance management");

    if (database.open()){
    // run our insert query
        QSqlQuery qry;
        qry.prepare("INSERT INTO teacher_has_a_course (crsCode, tchrID, tchrName)"
                    "VALUES (:crsCode, :tchrID, :tchrName)");

        qry.bindValue(":tchrID", tchrId);
        qry.bindValue(":crsCode", crsCode);
        qry.bindValue(":tchrName", tchrName);

        if(qry.exec()){
            state = 1;
            return state;

        } else {
            return state;
       }
    }

}

//std::list Admin::SearchTeacher(QString tchrId)
//{
  //  QSqlDatabase database;
    //database = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
//    database.setHostName("localhost");
  //  database.setUserName("root");
    //database.setPassword("");
//    database.setDatabaseName("attendance management");
//
  //  if(database.open()){
//
  //      QSqlQuery query(QSqlDatabase::database("MyConnect"));
//
  //              query.prepare(QString("SELECT * FROM teachers WHERE tchrID = :tchrID"));
//
  //              query.bindValue(":tchrID", tchrId);
//
//
  //              if(!query.exec()){
//
  //                  QMessageBox::information(this, "Error", "Query failed to execute.");
    //            } else {
//
  //                  while(query.next()){
//
  //                      QString tchrID = query.value(0).toString();
    //                    QString tchrName = query.value(1).toString();
      //                  QString tchrUsername = query.value(2).toString();
        //                QString tchrPassword = query.value(3).toString();
          //              QString tchrEmail = query.value(4).toString();
            //            QString tchrPhone = query.value(5).toString();
//


//                        QMessageBox::information(this, "", tchrID + "" + tchrName + "" + tchrUsername + "" + tchrPassword + "" + tchrEmail + "" + tchrPhone);
//
  //                      ui->tchrID->setText(tchrID);
    //                    ui->tchrName->setText(tchrName);
      //                  ui->tchrUsername->setText(tchrUsername);
        //                ui->tchrPassword->setText(tchrPassword);
          //              ui->tchrEmail->setText(tchrEmail);
            //            ui->tchrPhone->setText(tchrPhone);



              //          }
                //    }

    //}



//}


void Admin::on_registerBtn_clicked()
{
    QString stdUsername = ui->stdUsername->text();
    QString stdRollNo = ui->stdRollNo_2->text();
    QString stdName = ui->stdName_2->text();
    QString stdBatch = ui->stdBatch->text();
    QString stdPassword = ui->stdPassword->text();
    QString stdEmail = ui->stdEmail->text();
    QString stdPhone = ui->stdPhone->text();
    QString stdSection = ui->stdSection->text();

    Student rgstr;
    rgstr.stdRegister( stdRollNo, stdName, stdBatch, stdUsername,
                     stdPassword, stdEmail, stdPhone, stdSection);

}

