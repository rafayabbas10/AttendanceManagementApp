#include "student.h"

void Student::stdRegister(QString stdRollNo, QString stdName, QString stdBatch, QString stdUsername,
                          QString stdPassword, QString stdEmail, QString stdPhone, QString stdSection)
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
                qry.prepare("INSERT INTO students (stdRollNo, stdName, stdBatch, stdSection, stdUsername, stdPassword, stdEmail, stdPhone)"
                            "VALUES (:stdRollNo, :stdName, :stdBatch, :stdSection, :stdUsername, :stdPassword, :stdEmail, :stdPhone)");

                qry.bindValue(":stdPhone", stdPhone);
                qry.bindValue(":stdEmail", stdEmail);
                qry.bindValue(":stdPassword", stdPassword);
                qry.bindValue(":stdUsername", stdUsername);
                qry.bindValue(":stdSection", stdSection);
                qry.bindValue(":stdBatch", stdBatch);
                qry.bindValue(":stdName", stdName);
                qry.bindValue(":stdRollNo", stdRollNo);

                if(qry.exec()){
                    QMessageBox::information(this, "", "Records Updated");
                } else {
                    QMessageBox::information(this, "", "Database Connection Lost");
               }
         }
}


int Student::stdLogin(QString stdUsername, QString stdPassword)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("attendance management");
    int state = 0;

    if(db.open()){

        // creating my queries
        QSqlQuery query(QSqlDatabase::database("MyConnect"));

        query.prepare(QString("SELECT * FROM students WHERE stdUsername = :username AND stdPassword = :password"));

        query.bindValue(":username", stdUsername);
        query.bindValue(":password", stdPassword);

        if(!query.exec()){

            QMessageBox::information(this, "Error", "Query failed to execute.");
        } else {

            while(query.next()){

                QString usernameDb = query.value(4).toString();
                QString passswordDb = query.value(5).toString();

                if(usernameDb == stdUsername && passswordDb == stdPassword){
                    state = 1;
                    return state;

                } else {
                    QMessageBox::information(this, "Error", "Login Failed" + usernameDb + " " + passswordDb);

                    return state;
                }
            }

        }


    } else {

       QMessageBox::information(this, "Error", "Database Connection Failed");
       return state;
    }

}

int Student::attPercentage(QString stdRollNo, QString crsCode, QString tchrID)
{
    int attPercentage=101;
    float totalClasses=0;
    float stdClasses=0;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName("attendance management");

    if(db.open()){
        QSqlQuery qry(QSqlDatabase::database("MyConnect"));
        qry.prepare("SELECT COUNT(*) FROM attendance WHERE stdRollNo = :stdRollNo AND crsCode = :crsCode AND tchrID = :tchrID AND atdPresence = 1");
        qry.bindValue(":stdRollNo", stdRollNo);
        qry.bindValue(":crsCode", crsCode);
        qry.bindValue(":tchrID", tchrID);
        if(qry.exec()){
            while (qry.next()){
                stdClasses = qry.value(0).toInt();
            }
        } else {
            QMessageBox::information(this, "", "Error");
        }
        qry.prepare("SELECT COUNT(*) FROM class WHERE tchrID = :tchrID AND crsCode = crsCode");
        qry.bindValue(":tchrID", tchrID);
        qry.bindValue(":crsCode", crsCode);
        if(qry.exec()){
            while (qry.next()){
                totalClasses = qry.value(0).toInt();
            }
        } else {
            QMessageBox::information(this, "", "Error2");
        }
        if(totalClasses != 0 && stdClasses != 0){

            attPercentage = stdClasses/totalClasses*100;
            return attPercentage;
        } else {
            return attPercentage;
        }
    } else {
        return attPercentage;
    }
}

