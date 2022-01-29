#include "loginregister.h"



void LoginRegister::userRegister(QString username, QString password, QString email, QString phone, QString dbName)
{
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("");
    database.setDatabaseName(dbName);

    if (database.open()){


        // run our insert query
        if(dbName == "teachers"){
            QSqlQuery qry;
            qry.prepare("INSERT INTO teachers (username, password, email, phone)"
                        "VALUES (:username, :password, :email, :phone)");

            qry.bindValue(":dbName", dbName);
            qry.bindValue(":username", username);
            qry.bindValue(":password", password);
            qry.bindValue(":email", email);
            qry.bindValue(":phone", phone);

            if(qry.exec()){

                QMessageBox::information(this, "", "Records Updated");
            } else {
                QMessageBox::information(this, "", "Database Connection Lost");
            }
        } else {
            QSqlQuery qry;
            qry.prepare("INSERT INTO students (username, password, email, phone)"
                        "VALUES (:username, :password, :email, :phone)");

            qry.bindValue(":dbName", dbName);
            qry.bindValue(":username", username);
            qry.bindValue(":password", password);
            qry.bindValue(":email", email);
            qry.bindValue(":phone", phone);

            if(qry.exec()){

                QMessageBox::information(this, "", "Records Updated");
            } else {
                QMessageBox::information(this, "", "Database Connection Lost");
            }
        }

    } else{

        QMessageBox::information(this, "Error", "Database Connection Failed");

    }
}

int LoginRegister::userLogin(QString username, QString password, QString dbName)
{
    //connecting to mysql database
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QMYSQL", "MyConnect");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("");
    db.setDatabaseName(dbName);
    int state = 0;

    if(db.open()){

        // creating my queries
        QSqlQuery query(QSqlDatabase::database("MyConnect"));

        query.prepare(QString("SELECT * FROM teachers WHERE username = :username AND password = :password"));

        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if(!query.exec()){

            QMessageBox::information(this, "Error", "Query failed to execute.");
        } else {

            while(query.next()){

                QString usernameDb = query.value(1).toString();
                QString passswordDb = query.value(2).toString();

                if(usernameDb == username && passswordDb == password){

                    state = 1;
                    return state;
                } else {
                    QMessageBox::information(this, "Error", "Login Failed");
                }
            }

        }


    } else {

       QMessageBox::information(this, "Error", "Database Connection Failed");
    }



}
