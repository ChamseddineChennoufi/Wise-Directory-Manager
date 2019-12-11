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
    fournisseur(int,QString,QString,int);
    QString get_nom_societe();
    QString get_adresse();
    int get_id();
    int get_numtel();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &id);
    void exporterpdf(QTextBrowser *text);
private:
    QString adresse,nom_societe;
    int id,numtel;
};

#endif // FOURNISSEUR_H
