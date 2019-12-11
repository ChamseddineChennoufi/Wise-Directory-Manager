#ifndef ABONNES_H
#define ABONNES_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class abonnes
{public:
    abonnes();
    abonnes(int,QString,QString,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    QString get_email();
    QString get_date_inscription();
    QString get_livre_acheter();
    bool ajouter_2();
    QSqlQueryModel * afficher();
    bool supprimer_2(int);
    bool modifier_2(int);
    QSqlQueryModel * recherche(const QString &);
private:
    QString nom,prenom,email,date_inscription,livre_acheter;
    int id;
};
#endif // ABONNES_H
