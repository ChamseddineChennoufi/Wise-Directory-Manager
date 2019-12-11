#include "programme.h"
#include <QDebug>
Programme::Programme()
{
    IDEmp=0;
    NBRJ=0;
    NBRH=0;
    NJ=0;
}



Programme::Programme(int IDEmp, int NBRJ, int NBRH, int NJ)
{
    this->IDEmp=IDEmp;
    this->NBRJ=NBRJ;
    this->NBRH=NBRH;
    this->NJ=NJ;
}



int Programme::get_IDEmp(){return IDEmp;}
int Programme::get_NBJR(){return NBRJ;}
int Programme::get_NBRH(){return NBRH;}
int Programme::get_NJ(){return NJ;}





bool Programme::ajouter()
{
    QSqlQuery query;
    QString res1= QString::number(IDEmp);
    QString res2= QString::number(NBRJ);
    QString res3= QString::number(NBRH);
    QString res4= QString::number(NJ);

    query.prepare("INSERT INTO Emploies (IDEmp, NBRJ, NBRH, NJ) VALUES (:IDEmp, :NBRJ, :NBRH, :NJ)");

    query.bindValue(":IDEmp", res1);
    query.bindValue(":NBRJ", res2);
    query.bindValue(":NBRH", res3);
    query.bindValue(":NJ", res4);

    return    query.exec();
}

QSqlQueryModel * Programme::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Emploies");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Emploie"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nombre: Jours"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nombre: Heures"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nuit/Jour"));

    return model;
}

bool Programme::modifier(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    QString res1= QString::number(IDEmp);
    QString res2= QString::number(NBRJ);
    QString res3= QString::number(NBRH);
    QString res4= QString::number(NJ);
    query.prepare("UPDATE Emploies SET IDEmp=:IDEmp, NBRJ=:NBRJ, NBRH=:NBRH, NJ=:NJ WHERE IDEmp=:id");

    query.bindValue(":IDEmp", res1);
    query.bindValue(":NBRJ", res2);
    query.bindValue(":NBRH", res3);
    query.bindValue(":NJ", res4);
    query.bindValue(":id", res);


    return query.exec();
}

bool Programme::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from Emploies where IDEmp = :id ");
    query.bindValue(":id", res);
    return query.exec();
}

