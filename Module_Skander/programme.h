#ifndef PROGRAMME_H
#define PROGRAMME_H
#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Programme
{public:
    Programme();
    Programme(int,QString,QString);
    int get_Prog_ID();
    QString get_Poste();
    QString get_Section();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int);
    bool supprimer(int);
private:
    QString Section;
    int Prog_ID;
    QString Poste;

};

#endif // PROGRAMME_H
