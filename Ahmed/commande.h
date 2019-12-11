#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>



class commande
{
public:
    commande();
    commande(int,QString,int,QString,int);
     int get_reference();
    QString get_datec();
    QString get_nom_commande();
    int get_quantite();
    int get_id();
    bool ajouter_commande();
    QSqlQueryModel * afficher_commande();
    QSqlQueryModel *afficher_commande_trier();
    bool supprimer_commande(int);
    bool modifier_commande(int);
    QSqlQueryModel * calcul_quantite();
    QVector<double> stat();
private:
     QString datec;
     QString nom_commande;
    int quantite,reference;
    int id;
};

#endif // COMMANDE_H
