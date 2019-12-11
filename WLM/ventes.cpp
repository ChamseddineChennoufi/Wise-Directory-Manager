#include "ventes.h"


Ventes::Ventes()
{
    IDVent=00000000;
    ISBN=00000000;
    Quant=0;
    Price=0;
}
Ventes::Ventes(long IDVent, long ISBN, int Quant, double Price)
{
    this->IDVent=IDVent;
    this->ISBN=ISBN;
    this->Quant=Quant;
    this->Price=Price;
}

/*-----------------------------------------------------------------------------*/

bool Ventes::AddVente()
{
    QSqlQuery qry;
    QString SIDVent=QString::number(IDVent),SISBN=QString::number(ISBN),SQuant=QString::number(Quant),SPrice=QString::number(Price);

    qry.prepare("insert into Ventes (IDVent, ISBN, Quant, Price) Values (:IDVent, :ISBN, :Quant, :Price)");
    qry.bindValue(":IDVent",SIDVent);
    qry.bindValue(":ISBN",SISBN);
    qry.bindValue(":Quant",SQuant);
    qry.bindValue(":Price",SPrice);
    return qry.exec();
}

/*-----------------------------------------------------------------------------*/

QSqlQueryModel* Ventes::DisplayVente()
{
    QSqlQueryModel *Model= new QSqlQueryModel();

    Model->setQuery("select * from Ventes");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Vente"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ISBN"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix Totale"));

    return Model;
}

/*-----------------------------------------------------------------------------*/

QSqlQueryModel* Ventes::SearchISBN()
{
    QSqlQueryModel *Model= new QSqlQueryModel();
    //QSqlQuery qry;
    QString SIDVent=QString::number(IDVent);
    //qDebug("%ld",ISBN);
    //qry.prepare("Select * from Ventes where ISBN= :ISBN");
    //qry.bindValue(":ISBN",SISBN);

    Model->setQuery("Select * from Ventes where IDVent= "+SIDVent+"");
    Model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID Vente"));
    Model->setHeaderData(1,Qt::Horizontal,QObject::tr("ISBN"));
    Model->setHeaderData(2,Qt::Horizontal,QObject::tr("Quantité"));
    Model->setHeaderData(3,Qt::Horizontal,QObject::tr("Prix Totale"));
    return Model;
}

/*-----------------------------------------------------------------------------*/

bool Ventes::RemoveVente()
{
    QSqlQuery qry;
    QString SIDVent=QString::number(IDVent);

    qry.prepare("delete from Ventes where IDVent= :IDVent");
    qry.bindValue(":IDVent",SIDVent);
    return qry.exec();
}

/*-----------------------------------------------------------------------------*/

bool Ventes::RemoveAll()
{
    QSqlQuery qry;
    QString SQuant=QString::number(Quant);

    qry.prepare("delete from Ventes where Quant= :Quant");
    qry.bindValue(":Quant",SQuant);
    return qry.exec();
}

/*-----------------------------------------------------------------------------*/

bool Ventes::ModifyVente_Quant()
{
    QSqlQuery qry;
    QString SIDVent=QString::number(IDVent),SQuant=QString::number(Quant);

    qry.prepare("Update Ventes set Quant= :Quant where IDVent= :IDVent");
    qry.bindValue(":Quant",SQuant);
    qry.bindValue(":IDVent",SIDVent);
    return qry.exec();
}

/*-----------------------------------------------------------------------------*/

bool Ventes::ModifyVente_Price()
{
    QSqlQuery qry;
    QString SIDVent=QString::number(IDVent),SPrice=QString::number(Price);

    qry.prepare("Update Ventes set Price= :Price where IDVent= :IDVent");
    qry.bindValue(":Price",SPrice);
    qry.bindValue(":IDVent",SIDVent);
    return qry.exec();
}









Ventes::~Ventes()
{

}
















