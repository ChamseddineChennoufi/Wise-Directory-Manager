#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "sqldbt.h"
#include "ventes.h"
#include "agents.h"
#include "programme.h"
#include "fournisseur.h"
#include "etagere.h"
#include "livre.h"
#include "commande.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QStackedWidget>
#include <QApplication>
#include <QTabWidget>




QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QMainWindow
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    void checkdb(bool test);
    ~Login();

private slots:
    void on_LoginB_clicked();

    void on_Acceuil_clicked();

    void on_Inscriptions_clicked();

    void on_Livres_clicked();

    void on_Services_clicked();

    void on_EncV_clicked();

    void on_SupV_clicked();

    void on_ModQ_clicked();

    void on_ModP_clicked();

    void on_SrchV_clicked();

    void on_ReinitVAF_clicked();

    void on_SupTV_clicked();

    void on_Personnels_clicked();

    void on_Commandes_clicked();

    void on_Evenements_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_Modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_ajouter_P_clicked();

    void on_pb_Modifier_P_clicked();

    void on_pb_supprimer_P_clicked();


    void on_ajouterc_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_PushButton_Edit_clicked();

    void on_pb_rechercher_2_clicked();

    void on_supprimerc_clicked();

    void on_pushButton_clicked();

    void on_pb_ajouter_4_clicked();

    void on_pb_modifier_4_clicked();

    void on_pb_supprimer_5_clicked();

    void on_pb_modifier_5_clicked();

    void on_pb_ajouter_3_clicked();

    void on_pb_modifier_clicked();

    void on_pb_supprimer_4_clicked();

    void on_pb_rechercher_3_clicked();

private:
    Ui::Login *ui;
    Ventes TmpV;
    Employees tmpemployees;
    Programme tmpprogramme;
    fournisseur tmpfour;
    commande tmpcom;
    Livre tmplivre;
    Etagere tmpetagere;

};
#endif // LOGIN_H
