#include "teacher.h"

Teacher::Teacher(QWidget *parent) :
    QLabel(parent)
{


}

int Teacher::tchrRegister(QString Name, QString Username, QString Password, QString Email, QString Phone)
{
        int state = 0;
        QSqlDatabase database;
        database = QSqlDatabase::addDatabase("QMYSQL");
        database.setHostName("localhost");
        database.setUserName("root");
        database.setPassword("");
        database.setDatabaseName("attendance management");

        if (database.open()){


            // run our insert query
                QSqlQuery qry;
                qry.prepare("INSERT INTO teachers (tchrName, tchrUsername, tchrPassword, tchrEmail, tchrPhone)"
                            "VALUES (:tchrName, :tchrUsername, :tchrPassword, :tchrEmail, :tchrPhone)");

                qry.bindValue(":tchrPhone", Phone);
                qry.bindValue(":tchrEmail", Email);
                qry.bindValue(":tchrPassword", Password);
                qry.bindValue(":tchrUsername", Username);
                qry.bindValue(":tchrName", Name);


                if(qry.exec()){
                    state = 1;
                    return state;
                } else {
                    return state;

               }
         } else{
            return state;
        }
}


int Teacher::tchrLogin(QString Username, QString Password)
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

        query.prepare(QString("SELECT * FROM teachers WHERE tchrUsername = :username AND tchrPassword = :password"));

        query.bindValue(":username", Username);
        query.bindValue(":password", Password);

        if(!query.exec()){

            return state;
        } else {

            while(query.next()){

                QString usernameDb = query.value(2).toString();
                QString passswordDb = query.value(3).toString();

                if(usernameDb == Username && passswordDb == Password){
                    state = 1;
                    return state;

                } else {

                    return state;
                }
            }

        }

        return state;


    } else {

       return state;
    }

}

int Teacher::markAttendance(QString clsID, bool atdPresence, QString stdRollNo, QString crsCode, int tchrID){
    int state = 0;
    QSqlDatabase db9;
    db9 = QSqlDatabase::addDatabase("QMYSQL");
    db9.setHostName("localhost");
    db9.setUserName("root");
    db9.setPassword("");
    db9.setDatabaseName("attendance management");

    if(db9.open()){
        QSqlQuery qry;
        qry.prepare("INSERT INTO attendance (clsID, atdPresence, stdRollNo, crsCode, tchrID)"
                    "VALUES (:clsID, :atdPresence, :stdRollNo, :crsCode, :tchrID)");
        qry.bindValue(":clsID", clsID);
        qry.bindValue(":atdPresence", atdPresence);
        qry.bindValue(":stdRollNo", stdRollNo);
        qry.bindValue(":crsCode", crsCode);
        qry.bindValue(":tchrID", tchrID);
        if(qry.exec()){
            state = 1;
            return state;
        } else {

            return state;
        }
    } else {
        return state;
     }
}

void Teacher::setUsername(QString user)
{
    tchrUsername = user;
}

QString Teacher::getUsername()
{
    return tchrUsername;
}

void Teacher::setData()
{
}

void Teacher::nameOut()
{

}
