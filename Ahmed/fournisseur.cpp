#include "fournisseur.h"
#include<QFileInfo>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
fournisseur::fournisseur()
{
    id=0;
    nom_societe=" ";
    adresse=" ";
    numtel=0;

};
fournisseur::fournisseur(int id,QString nom_societe,QString adresse,int numtel)
{
    this->id=id;
    this->nom_societe=nom_societe;
    this->numtel=numtel;
    this->adresse=adresse;
}
int fournisseur::get_id(){return  id;}
QString fournisseur::get_adresse(){return adresse;}
QString fournisseur::get_nom_societe(){return  nom_societe;}
int fournisseur::get_numtel(){return  numtel;}
bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString rese=QString::number(numtel);
    query.prepare("INSERT INTO fournisseur (id,nom_societe,adresse,numtel)"
                  " VALUES (:id, :nom_societe,:adresse,:numtel)");
    query.bindValue(":id",res);
    query.bindValue(":nom_societe",nom_societe);
    query.bindValue(":adresse",adresse);
    query.bindValue(":numtel",rese);
    return  query.exec();
}
QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fournisseur");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_societe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("numtel"));

        return model;
}
bool fournisseur::supprimer(int id)
{
QSqlQuery query;
QString res= QString::number(id);
//QString rese=QString::number(numtel);
query.prepare("Delete from fournisseur where ID = :id ");
//query.prepare("Delete from fournisseur where NUMTEL = :numtel ");
query.bindValue(":id", res);
//query.bindValue(":numtel", rese);
return    query.exec();
}
bool fournisseur::modifier(int id)
{
    QSqlQuery query1;
     QSqlQuery query2;
      QSqlQuery query3;
       QSqlQuery query4;
       QSqlQuery query5;
        QSqlQuery query6;
   QString res= QString::number(id);
    QString rese=QString::number(numtel);
    if(nom_societe!="" && adresse=="" && numtel==0)
    {
   query1.prepare("UPDATE FOURNISSEUR SET NOM_SOCIETE=:nom_societe WHERE ID=:id");
   query1.bindValue(":id",res);
   query1.bindValue(":nom_societe",nom_societe);
   query1.bindValue(":adresse",adresse);
   query1.bindValue(":numtel",rese);
   return  query1.exec();
    }
    if(nom_societe=="" && adresse!="" && numtel==0)
    {
   query2.prepare("UPDATE FOURNISSEUR SET ADRESSE=:adresse WHERE ID=:id");
   query2.bindValue(":id",res);
   query2.bindValue(":nom_societe",nom_societe);
   query2.bindValue(":adresse",adresse);
   query2.bindValue(":numtel",rese);
   return  query2.exec();
    }
    if(nom_societe=="" && adresse=="" && numtel!=0)
    {
   query3.prepare("UPDATE FOURNISSEUR SET NUMTEL=:numtel WHERE ID=:id");
   query3.bindValue(":id",res);
   query3.bindValue(":nom_societe",nom_societe);
   query3.bindValue(":adresse",adresse);
   query3.bindValue(":numtel",rese);
   return  query3.exec();
    }
    if(nom_societe!="" && adresse!="" && numtel!=0)
    {
   query4.prepare("UPDATE FOURNISSEUR SET NOM_SOCIETE=:nom_societe,ADRESSE=:adresse,NUMTEL=:numtel WHERE ID=:id");
   query4.bindValue(":id",res);
   query4.bindValue(":nom_societe",nom_societe);
   query4.bindValue(":adresse",adresse);
   query4.bindValue(":numtel",rese);
   return  query4.exec();
    }
    if(nom_societe!="" && adresse=="" && numtel!=0)
    {
   query5.prepare("UPDATE FOURNISSEUR SET NOM_SOCIETE=:nom_societe,ADRESSE=:adresse,NUMTEL=:numtel WHERE ID=:id");
   query5.bindValue(":id",res);
   query5.bindValue(":nom_societe",nom_societe);
   query5.bindValue(":adresse",adresse);
   query5.bindValue(":numtel",rese);
   return  query5.exec();
    }
    if(nom_societe!="" && adresse!="" && numtel==0)
    {
   query6.prepare("UPDATE FOURNISSEUR SET NOM_SOCIETE=:nom_societe,ADRESSE=:adresse,NUMTEL=:numtel WHERE ID=:id");
   query6.bindValue(":id",res);
   query6.bindValue(":nom_societe",nom_societe);
   query6.bindValue(":adresse",adresse);
   query6.bindValue(":numtel",rese);
   return  query6.exec();
    }
}
QSqlQueryModel * fournisseur::recherche(const QString &id)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur where(ID LIKE '"+id+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SOCIETE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL"));
        return model;
}
/*void fournisseur::exporterpdf(QTextBrowser *text)
{
   QString tt;
    QSqlQuery qry;
    qry.exec("select* from repas");
    while(qry.next())
    {
        tt="qt: "+qry.value(0).toString()+"\n"+"Type: "+qry.value(1).toString()+"\n"+"Nom: "+qry.value(2).toString()+"\n";

    }
    text->setText(tt);
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);
    text->print(&printer);
}*/

