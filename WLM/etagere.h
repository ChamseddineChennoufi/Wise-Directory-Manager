#ifndef ETAGERE_H
#define ETAGERE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Etagere
{
public:
    Etagere();
    Etagere(long,int);
    long get_NumRayon();
    int get_etat();
    bool ajouter_2();
    bool modifier_4(long);
    QSqlQueryModel * modifier_5(const QString &id);
    QSqlQueryModel * afficher();
    bool supprimer_2(long);
private:
    long NumRayon;
    int State;
};

#endif // ETAGERE_H
