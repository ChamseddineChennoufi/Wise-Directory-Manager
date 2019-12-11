#ifndef VENTES_H
#define VENTES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class Ventes
{
    long IDVent,ISBN;
    int Quant;
    double Price;
public:
    Ventes();
    Ventes(long,long,int,double);
    void setidvent(long IDVent){this->IDVent=IDVent;}
    void setisbn(long ISBN){this->ISBN=ISBN;}
    void setquant(int Quant){this->Quant=Quant;}
    void setprice(double Price){this->Price=Price;}
    long getidvent(){return IDVent;}
    long getisbn(){return ISBN;}
    int getquant(){return Quant;}
    double getprice(){return Price;}
    bool AddVente();
    QSqlQueryModel* DisplayVente();
    QSqlQueryModel* SearchISBN();
    bool RemoveVente();
    bool RemoveAll();
    bool ModifyVente_Quant();
    bool ModifyVente_Price();
    ~Ventes();
};



#endif // VENTES_H
