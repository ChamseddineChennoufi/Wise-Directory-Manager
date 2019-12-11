#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class commande
{
public:
    commande();
    commande(long,QString,int,QString,long,long);
     long get_reference();
     long get_CINA();
    QString get_datec();
    QString get_nom_commande();
    int get_quantite();
    long get_idfour();
    bool ajouter_commande();
    QSqlQueryModel * afficher_commande();
    QSqlQueryModel *afficher_commande_trier();
    bool supprimer_commande(int);
    bool modifier_commande(int);
    QSqlQueryModel * calcul_quantite();
private:
     QString datec;
     QString nom_commande;
    int quantite;
    long idfour,reference,CINA;
};

#endif // COMMANDE_H
