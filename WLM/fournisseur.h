#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QTextBrowser>
class fournisseur
{
public:
    fournisseur();
    fournisseur(long,QString,QString,long);
    QString get_nom_societe();
    QString get_adresse();
    long get_idfour();
    long get_numtelf();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &id);
   //* void exporterpdf(QTextBrowser *text);
private:
    QString adresse,nom_societe;
    long idfour,numtelf;
};

#endif // FOURNISSEUR_H

