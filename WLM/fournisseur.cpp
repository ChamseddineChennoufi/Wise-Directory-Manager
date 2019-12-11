#include "fournisseur.h"
#include<QFileInfo>
#include<QFileDialog>
#include<QtPrintSupport/QPrinter>
fournisseur::fournisseur()
{
    idfour=0;
    nom_societe=" ";
    adresse=" ";
    numtelf=0;

};
fournisseur::fournisseur(long idfour,QString nom_societe,QString adresse,long numtelf)
{
    this->idfour=idfour;
    this->nom_societe=nom_societe;
    this->numtelf=numtelf;
    this->adresse=adresse;
}
long fournisseur::get_idfour(){return  idfour;}
QString fournisseur::get_adresse(){return adresse;}
QString fournisseur::get_nom_societe(){return  nom_societe;}
long fournisseur::get_numtelf(){return  numtelf;}

bool fournisseur::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(idfour);
    QString rese=QString::number(numtelf);
    query.prepare("INSERT INTO fournisseurs (idfour,nom_societe,adresse,numtelf) VALUES (:idfour, :nom_societe,:adresse,:numtelf)");
    query.bindValue(":idfour",res);
    query.bindValue(":nom_societe",nom_societe);
    query.bindValue(":adresse",adresse);
    query.bindValue(":numtelf",rese);
    return  query.exec();
}
QSqlQueryModel * fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from fournisseurs");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idfour"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_societe"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("numtelf"));

        return model;
}
bool fournisseur::supprimer(int idfour)
{
QSqlQuery query;
QString res= QString::number(idfour);
//QString rese=QString::number(numtel);
query.prepare("Delete from fournisseurs where IDFOUR = :idfour ");
//query.prepare("Delete from fournisseur where NUMTELF = :numtelf ");
query.bindValue(":idfour", res);
//query.bindValue(":numtelf", rese);
return    query.exec();
}
bool fournisseur::modifier(int idfour)
{
    QSqlQuery query1;
     QSqlQuery query2;
      QSqlQuery query3;
       QSqlQuery query4;
       QSqlQuery query5;
        QSqlQuery query6;
   QString res= QString::number(idfour);
    QString rese=QString::number(numtelf);
    if(nom_societe!="" && adresse=="" && numtelf==0)
    {
   query1.prepare("UPDATE FOURNISSEURS SET NOM_SOCIETE=:nom_societe WHERE IDFOUR=:idfour");
   query1.bindValue(":idfour",res);
   query1.bindValue(":nom_societe",nom_societe);
   query1.bindValue(":adresse",adresse);
   query1.bindValue(":numtelf",rese);
   return  query1.exec();
    }
    if(nom_societe=="" && adresse!="" && numtelf==0)
    {
   query2.prepare("UPDATE FOURNISSEURS SET ADRESSE=:adresse WHERE IDFOUR=:idfour");
   query2.bindValue(":idfour",res);
   query2.bindValue(":nom_societe",nom_societe);
   query2.bindValue(":adresse",adresse);
   query2.bindValue(":numtelf",rese);
   return  query2.exec();
    }
    if(nom_societe=="" && adresse=="" && numtelf!=0)
    {
   query3.prepare("UPDATE FOURNISSEURS SET NUMTELF=:numtelf WHERE IDFOUR=:idfour");
   query3.bindValue(":idfour",res);
   query3.bindValue(":nom_societe",nom_societe);
   query3.bindValue(":adresse",adresse);
   query3.bindValue(":numtelf",rese);
   return  query3.exec();
    }
    if(nom_societe!="" && adresse!="" && numtelf!=0)
    {
   query4.prepare("UPDATE FOURNISSEURS SET NOM_SOCIETE=:nom_societe,ADRESSE=:adresse,NUMTELF=:numtelf WHERE IDFOUR=:idfour");
   query4.bindValue(":idfour",res);
   query4.bindValue(":nom_societe",nom_societe);
   query4.bindValue(":adresse",adresse);
   query4.bindValue(":numtelf",rese);
   return  query4.exec();
    }
    if(nom_societe!="" && adresse=="" && numtelf!=0)
    {
   query5.prepare("UPDATE FOURNISSEURS SET NOM_SOCIETE=:nom_societe,ADRESSE=:adresse,NUMTELF=:numtelf WHERE IDFOUR=:idfour");
   query5.bindValue(":idfour",res);
   query5.bindValue(":nom_societe",nom_societe);
   query5.bindValue(":adresse",adresse);
   query5.bindValue(":numtelf",rese);
   return  query5.exec();
    }
    if(nom_societe!="" && adresse!="" && numtelf==0)
    {
   query6.prepare("UPDATE FOURNISSEURS SET NOM_SOCIETE=:nom_societe,ADRESSE=:adresse,NUMTELF=:numtelf WHERE IDFOUR=:idfour");
   query6.bindValue(":idfour",res);
   query6.bindValue(":nom_societe",nom_societe);
   query6.bindValue(":adresse",adresse);
   query6.bindValue(":numtelf",rese);
   return  query6.exec();
    }
}
QSqlQueryModel * fournisseur::recherche(const QString &idfour)
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs where(IDFOUR LIKE '"+idfour+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDFOUR"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM_SOCIETE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ADRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTELF"));
        return model;
}
/*
void fournisseur::exporterpdf(QTextBrowser *text)
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
}
*/
