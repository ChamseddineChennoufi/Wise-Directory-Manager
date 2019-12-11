#ifndef ABONNEMENT_H
#define ABONNEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Abonnement
{public:
    Abonnement();
    Abonnement(int,QString,int,int);
    int get_id();
    QString get_type();
    int get_prix();
    int get_duree();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *calcul_prix();
private:
   int id;
    QString type;
    int prix;
    int duree;
};

#endif // ABONNEMENT_H
