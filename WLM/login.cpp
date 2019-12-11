#include "login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
{
    QFont F;
    ui->setupUi(this);
    QPixmap BI("C:/Users/NightLurker/Desktop/Qt Projects/WLM/WLMbackground.jpg");
    QPixmap Icon("C:/Users/NightLurker/Desktop/Qt Projects/WLM/Wizard Librarian.png");
    ui->BackgroundSheet->setPixmap(BI);
    ui->BackgroundSheet_2->setPixmap(BI);
    ui->Icon->setPixmap(Icon);
    ui->stackedWidget->setCurrentIndex(0);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->VTab->setModel(TmpV.DisplayVente());
    ui->tabfour->setModel(tmpfour.afficher());
    ui->tabc->setModel(tmpcom.afficher_commande());
    ui->tabc_2->setModel(tmpcom.afficher_commande_trier());//refresh
    ui->tablecalcul->setModel(tmpcom.calcul_quantite());
    ui->tabemployees->setModel(tmpemployees.afficher());//refresh
    ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
    ui->tabetagere->setModel(tmpetagere.afficher());//refresh
    ui->tablivre->setModel(tmplivre.afficher());//refresh
}

void Login::checkdb(bool test)
{
    if(test!=true)
        {
            QMessageBox::critical(nullptr, QObject::tr("DataBase opening failed, "),QObject::tr("connection failed.\nClick OK to exit."),QMessageBox::Ok);
        }
}

Login::~Login()
{
    delete ui;
}


void Login::on_LoginB_clicked()
{
    QSqlQuery qry;
    QSqlQuery qryag;
    QString User=ui->le_usr->text();
    QString Pswd=ui->le_pwd->text();
    QString sqlqry="select * from Admins where usr=? and pwd=?";
    QString sqlqryag="select * from Agents where usr=? and pwd=?";
    QString sqlqryad="select * from Agents where usr=? and pwd=? and lvl=1";
    qry.prepare(sqlqry);
    qryag.prepare(sqlqryag);
    qry.addBindValue(ui->le_usr->text());
    qry.addBindValue(ui->le_pwd->text());
    qryag.addBindValue(ui->le_usr->text());
    qryag.addBindValue(ui->le_pwd->text());

    if (qry.exec())
    {
        int occlog1=0;
        while(qry.next())
        {
            occlog1++;
        }

        if(occlog1==1)
        {
            ui->stackedWidget->setCurrentIndex(1);
            qDebug() << "Prop verified!";  //interface for prop to be added here
        }
        else
        {
            if (qryag.exec())
            {
                int occlog2=0,occadm=0;
                while(qryag.next())
                {
                    occlog2++;
                }
                if(occlog2==1)
                {
                    qryag.prepare(sqlqryad);
                    qryag.addBindValue(ui->le_usr->text());
                    qryag.addBindValue(ui->le_pwd->text());
                    if(qryag.exec())
                    {
                        while(qryag.next())
                        {
                            occadm++;
                        }
                        if(occadm==1)
                        {
                            qDebug()<<"Admin Verified"; //interface for admin to be added here
                        }
                        else
                        {
                            qDebug()<<"Agents Verified"; //interface for agent to be added here
                        }
                    }
                }
                else
                {

                    ui->StatusReport->setText("<font size=1.8><font color='red'>Wrong Username and/or Password! Try Again!</font></font>");

                }
            }
        }
    }
}










void Login::on_Acceuil_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}

void Login::on_Inscriptions_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
}

void Login::on_Livres_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void Login::on_Services_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void Login::on_Personnels_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(4);
}

void Login::on_Commandes_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(5);
}

void Login::on_Evenements_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(6);
}

void Login::on_EncV_clicked()
{
    Ventes V(ui->LE_IDVentVA->text().toLong(),ui->LE_ISBNVA->text().toLong(),ui->LE_QuantVA->text().toInt(),ui->LE_PriceVA->text().toDouble());

    if(V.AddVente())
    {
        ui->VTab->setModel(TmpV.DisplayVente());
        ui->Txt_VA->setText("<font size =1.8><font color='green'>Achat encaisser avec succès!</font></font>");
    }
    else
    {
        ui->Txt_VA->setText("<font color='red'>Achat échoué!</font>");
    }

}


void Login::on_SupV_clicked()
{
    Ventes V;
    V.setidvent(ui->LE_IDVentVS->text().toLong());
    if(V.RemoveVente())
    {
        ui->VTab->setModel(TmpV.DisplayVente());
        ui->Txt_VS->setText("<font size =2.5><font color='green'>Achat Supprimer!</font></font>");
    }
    else
    {
        ui->Txt_VA->setText("<font color='red'>Suppression échoué!</font>");
    }
}

void Login::on_ModQ_clicked()
{
    Ventes V;
    V.setidvent(ui->LE_IDVentVM->text().toLong());
    V.setquant(ui->LE_QuantVM->text().toInt());
    if(V.ModifyVente_Quant())
    {
        ui->VTab->setModel(TmpV.DisplayVente());
        ui->Txt_VM->setText("<font size =2.5><font color='green'>Achat Modifier!</font></font>");
    }
    else
    {
        ui->Txt_VM->setText("<font color='red'>Modification échoué!</font>");
    }
}

void Login::on_ModP_clicked()
{
    Ventes V;
    V.setidvent(ui->LE_IDVentVM->text().toLong());
    V.setprice(ui->LE_PriceVM->text().toDouble());
    if(V.ModifyVente_Price())
    {
        ui->VTab->setModel(TmpV.DisplayVente());
        ui->Txt_VM->setText("<font size =2.5><font color='green'>Achat Modifier!</font></font>");
    }
    else
    {
        ui->Txt_VM->setText("<font color='red'>Modification échoué!</font>");
    }
}

void Login::on_SrchV_clicked()
{
    Ventes V;
    V.setidvent(ui->LE_IDVentVAF->text().toLong());
    ui->VTab->setModel(V.SearchISBN());
}

void Login::on_ReinitVAF_clicked()
{
    ui->VTab->setModel(TmpV.DisplayVente());
}

void Login::on_SupTV_clicked()
{
    Ventes V;
    int i=0;

    for(i=0;i<99;i++)
    {
        V.setquant(i);
        V.RemoveAll();
        ui->VTab->setModel(V.SearchISBN());
    }
    ui->Txt_VS->setText("<font size =2.5><font color='green'>Touts les Achats on ete supprimer!</font></font>");
}

/*--------------------------------SKANDER-----------------------------------*/


void Login::on_pb_ajouter_clicked()
{
    long CINA = ui->lineEdit_id->text().toInt();
    QString Nom= ui->lineEdit_nom->text();
    QString Prenom= ui->lineEdit_prenom->text();
    QString Usr= ui->lineEdit_Usr->text();
    QString Pwd= ui->lineEdit_Pwd->text();
    double Salary= ui->lineEdit_Salary->text().toInt();
    int lvl= ui->lineEdit_lvl->text().toInt();
    long IDEmp= ui->lineEdit_IDEmp->text().toInt();
    QString Email= ui->lineEdit_Email->text();
    long NumTel= ui->lineEdit_Tel->text().toInt();
    QString Adresse= ui->lineEdit_Adresse->text();

    Employees e(CINA,Nom,Prenom,Usr,Pwd,Salary,lvl,IDEmp,Email,NumTel,Adresse);
    bool test=e.ajouter();
    if(test)
    {
        ui->tabemployees->setModel(tmpemployees.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Employé"),
        QObject::tr("Employé ajouté.\n Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un Employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }

}





void Login::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpemployees.supprimer(id);
    if(test)
    {
        ui->tabemployees->setModel(tmpemployees.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
        QObject::tr("Employé supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
        QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    }

}


void Login::on_pb_Modifier_clicked()
{
    long CINA = ui->lineEdit_id_M->text().toInt();
    QString Nom= ui->lineEdit_nom_M->text();
    QString Prenom= ui->lineEdit_prenom_M->text();
    QString Usr= ui->lineEdit_Usr_M->text();
    QString Pwd= ui->lineEdit_Pwd_M->text();
    double Salary= ui->lineEdit_Salary_M->text().toInt();
    int lvl= ui->lineEdit_lvl_M->text().toInt();
    long IDEmp= ui->lineEdit_IDEmp_M->text().toInt();
    QString Email= ui->lineEdit_Email_M->text();
    long NumTel= ui->lineEdit_Tel_M->text().toInt();
    QString Adresse= ui->lineEdit_Adresse_M->text();

    Employees e(CINA,Nom,Prenom,Usr,Pwd,Salary,lvl,IDEmp,Email,NumTel,Adresse);
    bool test=e.modifier(CINA);
    if(test)
    {
        ui->tabemployees->setModel(tmpemployees.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier Employé"),
                  QObject::tr("Employé modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_rechercher_clicked()
{
    QString id = ui->lineEdit_id_R->text();
    ui->tabemployees_3->setModel(tmpemployees.recherche(id));
}

void Login::on_pb_ajouter_P_clicked()
{
    int IDEmp= ui->lineEdit_IDEmp_P->text().toInt();
    int NBRJ= ui->lineEdit_NBRJ->text().toInt();
    int NBRH= ui->lineEdit_NBRH->text().toInt();
    int NJ= ui->lineEdit_NJ->text().toInt();

    Programme p(IDEmp,NBRJ,NBRH,NJ);
    bool test=p.ajouter();
    if(test)
    {
        ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un Programme"),
                    QObject::tr("Programme ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Programme"),
                      QObject::tr("Erreur !.\n Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_Modifier_P_clicked()
{
    int IDEmp= ui->lineEdit_IDEmp_P_M->text().toInt();
    int NBRJ= ui->lineEdit_NBRJ_M->text().toInt();
    int NBRH= ui->lineEdit_NBRH_M->text().toInt();
    int NJ= ui->lineEdit_NJ_M->text().toInt();

    Programme p(IDEmp,NBRJ,NBRH,NJ);
    bool test=p.modifier(IDEmp);
    if(test)
    {
        ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier Programme"),
                  QObject::tr("Programme modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier Programme"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_supprimer_P_clicked()
{
    int id= ui->lineEdit_id_S->text().toInt();
    bool test=tmpprogramme.supprimer(id);
    if(test)
    {
        ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un programme"),
                    QObject::tr("Programme supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un programme"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

/*-----------------------------AHMED-----------------------------------*/

void Login::on_ajouterc_clicked()
{
    int reference = ui->lineEdit_ref->text().toInt();
    QString datec= ui->lineEdit_datec->text();
    int quantite=ui->lineEdit_quan->text().toInt();
    QString nom_commande=ui->lineEdit_nomc_2->text();
    long idfour=ui->lineEdit_idd->text().toInt();
    long CINA=ui->lineEdit_cin->text().toInt();
  commande c(reference,datec,quantite,nom_commande,idfour,CINA);
  bool test=c.ajouter_commande();
  if(test)
{ui->tabc->setModel(tmpcom.afficher_commande());
      ui->tabc_2->setModel(tmpcom.afficher_commande_trier());//refresh
      ui->tablecalcul->setModel(tmpcom.calcul_quantite());
QMessageBox::information(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("commande ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pb_ajouter_2_clicked()
{
    long idfour = ui->lineEdit_id_3->text().toInt();
    QString nom_societe= ui->lineEdit_nom_societe->text();
    QString adresse= ui->lineEdit_adresse->text();
    long numtelf=ui->lineEdit_numtel->text().toInt();
  fournisseur f(idfour,nom_societe,adresse,numtelf);
  bool test=f.ajouter();
  if(test)
{ui->tabfour->setModel(tmpfour.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("fournisseur ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pb_supprimer_2_clicked()
{
    long idfour = ui->lineEdit_id_4->text().toInt();
    bool test=tmpfour.supprimer(idfour);
    if(test)
    {ui->tabfour->setModel(tmpfour.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                                 QObject::tr("fournisseur supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr, QObject::tr(" fournisseur inexistant"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



}

void Login::on_PushButton_Edit_clicked()
{
    long idfour = ui->lineEdit_ide->text().toInt();
    QString nom_societe= ui->lineEdit_nom_societe_2->text();
    QString adresse= ui->lineEdit_adresse_2->text();
    long numtelf=ui->lineEdit_numtel_2->text().toInt();
    fournisseur f1(idfour,nom_societe,adresse,numtelf);
  bool test=f1.modifier(idfour);
  if(test)
{ui->tabfour->setModel(tmpfour.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void Login::on_pb_rechercher_2_clicked()
{
    QString str=ui->lineEdit_rechercher->text();
    ui->tabrecherche->setModel(tmpfour.recherche(str));
}

void Login::on_supprimerc_clicked()
{
    long reference = ui->lineEdit_4->text().toInt();
    bool test=tmpcom.supprimer_commande(reference);
    if(test)
    {ui->tabc->setModel(tmpcom.afficher_commande());
        ui->tabc_2->setModel(tmpcom.afficher_commande_trier());//refresh
        ui->tablecalcul->setModel(tmpcom.calcul_quantite());
        QMessageBox::information(nullptr, QObject::tr("Supprimer une commande"),
                                 QObject::tr("commande supprimé.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une commande"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Login::on_pushButton_clicked()
{
    int reference = ui->lineEdit_ref_2->text().toInt();
    QString datec= ui->lineEdit_d->text();
    int quantite=ui->lineEdit_3->text().toInt();
    QString nom_commande= ui->lineEdit_nomc->text();
    int idfour=ui->lineEdit_iddd->text().toInt();

    commande c1(reference,datec,quantite,nom_commande,idfour,0);
    bool test=c1.modifier_commande(reference);
    if(test)
    {
        ui->tabc->setModel(tmpcom.afficher_commande());
        ui->tabc_2->setModel(tmpcom.afficher_commande_trier());//refresh
        ui->tablecalcul->setModel(tmpcom.calcul_quantite());
        QMessageBox::information(nullptr, QObject::tr("modifier une commande"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
    {
        QMessageBox::critical(nullptr, QObject::tr("modifier une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

/*-----------------------------------------------Bedis---------------------------------------------*/
void Login::on_pb_ajouter_4_clicked()
{
    long NumRayon = ui->lineEdit_id_9->text().toInt();
    int State= ui->lineEdit_etat->text().toInt();
    Etagere e(NumRayon,State);
    bool test=e.ajouter_2();
    if(test)
    {
        ui->tabetagere->setModel(tmpetagere.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter une étagère"),
                  QObject::tr("Etagère ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter une étagère"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}



void Login::on_pb_modifier_4_clicked()
{

    long NumRayon = ui->lineEdit_idmod_2->text().toInt();
    int State= ui->lineEdit_etatmod->text().toInt();

    Etagere e(NumRayon,State);
    bool test=e.modifier_4(NumRayon);
    if(test)
    {
        ui->tabetagere->setModel(tmpetagere.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier une étagère"),
                  QObject::tr("Etagère modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier étagère"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_supprimer_5_clicked()
{
    long NumRayon = ui->lineEdit_id_10->text().toInt();
    bool test=tmpetagere.supprimer_2(NumRayon);
    if(test)
    {
        ui->tabetagere->setModel(tmpetagere.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une étagère"),
                    QObject::tr("Etagère supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une étagère"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_modifier_5_clicked()
{
    QString str=ui->lineEdit_idmod_3->text();
    ui->tabrecherche2->setModel(tmpetagere.modifier_5(str));
}

void Login::on_pb_ajouter_3_clicked()
{
    long ISBN= ui->lineEdit_id_7->text().toLong();
    QString Title= ui->lineEdit_Title->text();
    QString Author= ui->lineEdit_Author->text();
    long NumRayon=ui->lineEdit_NumRayon->text().toLong();
    long CINA=ui->lineEdit_CINA_Liv->text().toLong();

    Livre l(ISBN,Title,Author,NumRayon,CINA);
    bool test=l.ajouter();
    if(test)
    {
        ui->tablivre->setModel(tmplivre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Ajouter un livre"),
                QObject::tr("Livre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un livre"),
                QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_modifier_clicked()
{
    long ISBN= ui->lineEdit_id_ISBN_M->text().toLong();
    QString Title= ui->lineEdit_Title_M->text();
    QString Author= ui->lineEdit_Author_M->text();
    long NumRayon=ui->lineEdit_NumRayon_M->text().toLong();
    long CINA=ui->lineEdit_CINA_Liv_M->text().toLong();

    Livre l(ISBN,Title,Author,NumRayon,CINA);
    bool test=l.modifier(ISBN);
    if(test)
    {
        ui->tablivre->setModel(tmplivre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Modifier un livre"),
                QObject::tr("Livre modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier livre"),
                QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_supprimer_4_clicked()
{
    long ISBN=ui->lineEdit_id_8->text().toLong();
    bool test=tmplivre.supprimer(ISBN);
    if(test)
    {
        ui->tablivre->setModel(tmplivre.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un livre"),
                  QObject::tr("Livre supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un livre"),
                  QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void Login::on_pb_rechercher_3_clicked()
{
    QString str=ui->lineEdit_rechercher_2->text();
    ui->tabrecherche_2->setModel(tmplivre.recherche(str));
}
