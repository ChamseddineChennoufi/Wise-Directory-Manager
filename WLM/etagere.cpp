#include "etagere.h"

Etagere::Etagere()
{
NumRayon=0;
State=0;
}
Etagere::Etagere(long NumRayon, int State)
{
    this->NumRayon=NumRayon;
    this->State=State;
}
long Etagere::get_NumRayon(){return NumRayon;}
int Etagere::get_etat(){return  State;}

bool Etagere::ajouter_2()
{
QSqlQuery query;
QString res= QString::number(NumRayon);
QString res1= QString::number(State);

query.prepare("INSERT INTO etagere (NumRayon, State) VALUES (:NumRayon, :State)");
query.bindValue(":NumRayon", res);
query.bindValue(":State", res1);


return    query.exec();
}

QSqlQueryModel * Etagere::afficher()

{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from etagere");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero Rayon"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}

bool Etagere::supprimer_2(long NumRayon)
{
QSqlQuery query;
QString res= QString::number(NumRayon);
query.prepare("Delete from etagere where NumRayon = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool Etagere::modifier_4(long idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    QString res1= QString::number(State);
    query.prepare("UPDATE etagere SET State=:State WHERE NumRayon=:id");
    query.bindValue(":id", res);
    query.bindValue(":State", res1);

    return    query.exec();
}

QSqlQueryModel * Etagere::modifier_5(const QString &id)//recherche et non pas modifier
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from etagere where(NumRayon LIKE '"+id+"')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero Rayon"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));

        return model;
}
