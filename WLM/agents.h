#ifndef AGENTS_H
#define AGENTS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDate>

class Employees
{public:
    Employees();
    Employees(long CINA,QString Nom,QString Prenom,QString Usr,QString Pwd, double Salary,int lvl, long IDEmp, QString Email,long NumTel,QString Adresse);
    long get_CINA();
    QString get_Nom();
    QString get_Prenom();
    QString get_Email();
    long get_NumTel();
    QString get_Adresse();
    QString get_User();
    QString get_Pwd();
    int get_lvl();

    bool ajouter();
    bool modifier(long);
    QSqlQueryModel * afficher();
    QSqlQueryModel * recherche(const QString &Employee_ID );
    bool supprimer(int);
private:
    QString Nom,Prenom,Usr,Pwd,Email,Adresse;
    int lvl,IDEmp;
    double Salary;
    long CINA,NumTel;

};

#endif // AGENTS_H
