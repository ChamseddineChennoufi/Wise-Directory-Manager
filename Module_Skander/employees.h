#ifndef EMPLOYEES_H
#define EMPLOYEES_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>
class Employees
{public:
    Employees();
    Employees(int,QString,QString,int,QString,int,QString,QString,QString,int);
    int get_Emp_ID();
    QString get_Nom();
    QString get_Prenom();
    int get_CIN();

    QString get_Email();
    int get_NumTel();
    QString get_Adresse();
    QString get_Grade();
    QString get_Fonction();
    int get_ProgID();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
     QSqlQueryModel * recherche(const QString &Employee_ID );
    bool supprimer(int);
private:
    QString Nom,Prenom,Email,Adresse,Grade,Fonction;
    int Employee_ID,CIN,Num_Tel,Prog_iD;

};

#endif // EMPLOYEES_H
