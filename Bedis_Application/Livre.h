#ifndef LIVRE_H
#define LIVRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Livre
{public:
    Livre();
    Livre(int,QString,QString);
    QString get_titre();
    QString get_auteur();
    int get_id();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * afficher();

    bool supprimer(int);
private:
    QString titre,auteur;
    int id;
};

#endif // LIVRE_H
