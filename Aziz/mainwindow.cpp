#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "abonnement.h"
#include "abonnes.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
QPixmap bg("C:/Users/AZIZ AKARI/Desktop/crud/Atelier_Crud_Vf/WLMbackground.jpg");
ui->img->setPixmap(bg);
ui->tab_abonnements->setModel(tmpabonnement.afficher());
ui->tab_abonnes->setModel(tmpabonnes.afficher());
ui->calcul_tableview->setModel(tmpabonnement.calcul_prix());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString type= ui->lineEdit_type->text();
    int prix= ui->lineEdit_prix->text().toInt();
    int duree=ui->lineEdit_duree->text().toInt();
  Abonnement e(id,type,prix,duree);
  bool test=e.ajouter();
  if(test)
{ui->tab_abonnements->setModel(tmpabonnement.afficher());
      ui->calcul_tableview->setModel(tmpabonnement.calcul_prix());         //refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un abonnement"),
                  QObject::tr("abonnement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpabonnement.supprimer(id);
if(test)
{ui->tab_abonnements->setModel(tmpabonnement.afficher());
    ui->calcul_tableview->setModel(tmpabonnement.calcul_prix());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un abonnement"),
                QObject::tr("abonnement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonnement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString email= ui->lineEdit_email->text();
    QString date_inscription= ui->lineEdit_date_inscription->text();
    QString livre_acheter= ui->lineEdit_livre_acheter->text();

  abonnes a(id,nom,prenom,email,date_inscription,livre_acheter);
  bool test=a.ajouter_2();
  if(test)
{ui->tab_abonnes->setModel(tmpabonnes.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un abonne"),
                  QObject::tr("abonne ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un abonne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmpabonnes.supprimer_2(id);
    if(test)
    {ui->tab_abonnes->setModel(tmpabonnes.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un abonne"),
                    QObject::tr("abonne supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un abonne"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit_idmod->text().toInt();
    QString type= ui->lineEdit_typemod->text();
    int prix= ui->lineEdit_prixmod->text().toInt();
    int duree= ui->lineEdit_dureemod->text().toInt();
   Abonnement abon(id,type,prix,duree);
  bool test=abon.modifier(id);
  if(test)
{ui->tab_abonnements->setModel(tmpabonnement.afficher());
      ui->calcul_tableview->setModel(tmpabonnement.calcul_prix());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un abonnement"),
                  QObject::tr("Abonnement modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier abonnement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_iddmod->text().toInt();
    QString nom= ui->lineEdit_nommod->text();
     QString prenom= ui->lineEdit_prenommod->text();
      QString email= ui->lineEdit_emailmod->text();
       QString date_inscription= ui->lineEdit_datemod->text();
        QString livre_acheter= ui->lineEdit_livremod->text();


   abonnes abonnes(id,nom,prenom,email,date_inscription,livre_acheter);
  bool test=abonnes.modifier_2(id);
  if(test)
{ui->tab_abonnes->setModel(tmpabonnes.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un abonne"),
                  QObject::tr("Abonne modifier.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier abonne"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_Rechercher_clicked()
{
  QString id = ui->lineEdit_id_5->text();
ui->tabrech->setModel(tmpabonnes.recherche(id));
}
