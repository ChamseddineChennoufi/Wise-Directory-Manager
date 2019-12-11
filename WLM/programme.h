#ifndef PROGRAMME_H
#define PROGRAMME_H
#include <QString>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Programme
{
public:
    Programme();
    Programme(int,int,int,int);
    int get_IDEmp();
    int get_NBJR();
    int get_NBRH();
    int get_NJ();


    bool ajouter();
    QSqlQueryModel * afficher();
    bool modifier(int);
    bool supprimer(int);
private:
    int NBRJ,NBRH,NJ,IDEmp;

};

#endif // PROGRAMME_H
