#include "commande.h"

commande::commande()
{
   reference=0;
   datec=" ";
   quantite=0;
   nom_commande=" ";
   id=0;
}
commande::commande(int reference,QString datec,int quantite,QString nom_commande,int id)
{
    this->reference=reference;
    this->datec=datec;
    this->quantite=quantite;
    this->nom_commande=nom_commande;
    this->id=id;

}
int commande::get_reference(){return  reference;}
QString commande::get_datec(){return datec;}
int commande::get_quantite(){return  quantite;}
QString commande::get_nom_commande(){return  nom_commande;}
int commande::get_id(){return id;}
bool commande::ajouter_commande()
{
    QSqlQuery query;
    QString res= QString::number(reference);
    QString rese=QString::number(quantite);
    QString re=QString::number(id);
    query.prepare("INSERT INTO commande (reference,datec,quantite,nom_commande,id)"
                  " VALUES (:reference, :datec,:quantite,:nom_commande,:id)");
    query.bindValue(":reference",res);
    query.bindValue(":datec",datec);
    query.bindValue(":quantite",rese);
    query.bindValue(":nom_commande",nom_commande);
    query.bindValue(":id",re);
    return  query.exec();
}
QSqlQueryModel * commande::afficher_commande()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from commande");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datec"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_commande"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("id"));


        return model;
}
bool commande::supprimer_commande(int reference)
{
QSqlQuery query;
QString res= QString::number(reference);
query.prepare("Delete from commande where REFERENCE = :reference ");
query.bindValue(":reference", res);
return    query.exec();
}
bool commande::modifier_commande(int refernce)
{
    QSqlQuery query1;
     QSqlQuery query2;
      QSqlQuery query3;
       QSqlQuery query4;
       QSqlQuery query5;
        QSqlQuery query6;
   QString res= QString::number(refernce);
    QString rese=QString::number(quantite);
    if(nom_commande!="" && datec=="" && quantite==0)
    {
   query1.prepare("UPDATE COMMANDE SET NOM_COMMANDE=:nom_commande WHERE REFERENCE=:reference");
   query1.bindValue(":reference",res);
   query1.bindValue(":nom_commande",nom_commande);
   query1.bindValue(":datec",datec);
   query1.bindValue(":quantite",rese);
   return  query1.exec();
    }
    if(nom_commande=="" && datec!="" && quantite==0)
    {
        query2.prepare("UPDATE COMMANDE SET DATEC=:datec WHERE REFERENCE=:reference");
        query2.bindValue(":reference",res);
        query2.bindValue(":nom_commande",nom_commande);
        query2.bindValue(":datec",datec);
        query2.bindValue(":quantite",rese);
   return  query2.exec();
    }
    if(nom_commande=="" && datec=="" && refernce!=0)
    {
   query3.prepare("UPDATE COMMANDE SET QUANTITE=:quantite WHERE REFERENCE=:reference");
   query3.bindValue(":reference",res);
   query3.bindValue(":nom_commande",nom_commande);
   query3.bindValue(":datec",datec);
   query3.bindValue(":quantite",rese);
   return  query3.exec();
    }
    if(nom_commande!="" && datec!="" && quantite!=0)
    {
   query4.prepare("UPDATE COMMANDE SET NOM_COMMANDE=:nom_commande,DATEC=:datec,QUANTITE=:quantite WHERE REFERENCE=:reference");
   query4.bindValue(":reference",res);
   query4.bindValue(":nom_commande",nom_commande);
   query4.bindValue(":datec",datec);
   query4.bindValue(":quantite",quantite);
   return  query4.exec();
    }
    if(nom_commande!="" && datec=="" && quantite!=0)
    {
   query5.prepare("UPDATE COMMANDE SET NOM_COMMANDE=:nom_commande,DATEC=:datec,QUANTITE=:quantite WHERE REFERENCE=:reference");
   query5.bindValue(":reference",res);
   query5.bindValue(":nom_commande",nom_commande);
   query5.bindValue(":datec",datec);
   query5.bindValue(":quantite",rese);
   return  query5.exec();
    }
    if(nom_commande!="" && datec!="" && quantite==0)
    {
   query6.prepare("UPDATE COMMANDE SET NOM_COMMANDE=:nom_commande,DATEC=:datec,QUANTITE=:quantite WHERE REFERENCE=:reference");
   query6.bindValue(":reference",res);
   query6.bindValue(":nom_commande",nom_commande);
   query6.bindValue(":datec",datec);
   query6.bindValue(":quantite",rese);
   return  query6.exec();
    }
}
QSqlQueryModel * commande::afficher_commande_trier()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from commande ORDER BY DATEC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("datec"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_commande"));
      /*model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));*/


        return model;
}
QSqlQueryModel * commande::calcul_quantite()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select sum(quantite) from commande");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("quantite"));
    return  model;
}
QVector<double> commande:: stat()
{
    QSqlQuery q;
        QVector<double> stat(12);
        stat[0]=0;
        stat[1]=0;
        stat[2]=0;
        stat[3]=0;
        stat[4]=0;
        stat[5]=0;
        stat[6]=0;
        stat[7]=0;
        stat[8]=0;
        stat[9]=0;
        stat[10]=0;
        stat[11]=0;
        q.prepare("SELECT * FROM commande WHERE 1.1<=DATEC and DATEC<=1.31");
        q.exec();
        while (q.next())
        {
            stat[0]++;
        }
        q.prepare("SELECT * FROM commande WHERE 1.1<=DATEC and DATEC<=1.31");
        q.exec();
        while (q.next())
        {
            stat[1]++;
        }
        q.prepare("SELECT * FROM commande WHERE 2.1<=DATEC and DATEC<=2.31");
        q.exec();
        while (q.next())
        {
            stat[2]++;
        }
        q.prepare("SELECT * FROM commande WHERE 3.1<=DATEC and DATEC<=3.31");
        q.exec();
        while (q.next())
        {
            stat[3]++;
        }
        q.prepare("SELECT * FROM commande WHERE 4.1<=DATEC and DATEC<=4.31");
        q.exec();
        while (q.next())
        {
            stat[4]++;
        }
        q.prepare("SELECT * FROM commande WHERE 5.1<=DATEC and DATEC<=5.31");
        q.exec();
        while (q.next())
        {
            stat[5]++;
        }
        q.prepare("SELECT * FROM commande WHERE 6.1<=DATEC and DATEC<=6.31");
        q.exec();
        while (q.next())
        {
            stat[6]++;
        }
        q.prepare("SELECT * FROM commande WHERE 7.1<=DATEC and DATEC<=7.31");
        q.exec();
        while (q.next())
        {
            stat[7]++;
        }
        q.prepare("SELECT * FROM commande WHERE 8.1<=DATEC and DATEC<=8.31");
        q.exec();
        while (q.next())
        {
            stat[8]++;
        }
        q.prepare("SELECT * FROM commande WHERE 9.1<=DATEC and DATEC<=9.31");
        q.exec();
        while (q.next())
        {
            stat[9]++;
        }
        q.prepare("SELECT * FROM commande WHERE 10.1<=DATEC and DATEC<=10.31");
        q.exec();
        while (q.next())
        {
            stat[10]++;
        }
        q.prepare("SELECT * FROM commande WHERE 11.1<=DATEC and DATEC<=11.31");
        q.exec();
        while (q.next())
        {
            stat[11]++;
        }
}
