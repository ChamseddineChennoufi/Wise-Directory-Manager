#ifndef LIVRE_H
#define LIVRE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Livre
{
public:

    Livre();
    Livre(long,QString,QString,long,long);
    QString get_Title();
    QString get_Author();
    long get_ISBN();
    long get_CINA();
    long get_NumRayon();
    bool ajouter();
    bool modifier(long);
    QSqlQueryModel * recherche(const QString &id);
    QSqlQueryModel * afficher();
    bool supprimer(long);

private:

    QString Title,Author;
    long ISBN,CINA,NumRayon;
};

#endif // LIVRE_H
