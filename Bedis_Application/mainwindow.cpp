#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Livre.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tablivre->setModel(tmplivre.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString titre= ui->lineEdit_titre->text();
    QString auteur= ui->lineEdit_auteur->text();
  Livre l(id,titre,auteur);
  bool test=l.ajouter();
  if(test)
{ui->tablivre->setModel(tmplivre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un livre"),
                  QObject::tr("Livre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un livre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmplivre.supprimer(id);
if(test)
{ui->tablivre->setModel(tmplivre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un livre"),
                QObject::tr("Livre supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un livre"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    int quantite = ui->lineEdit_quantite->text().toInt();
    QString etat= ui->lineEdit_etat->text();
  Etagere e(id,quantite,etat);
  bool test=e.ajouter_2();
  if(test)
{ui->tabetagere->setModel(tmpetagere.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une étagère"),
                  QObject::tr("Etagère ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une étagère"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpetagere.supprimer_2(id);
    if(test)
    {ui->tabetagere->setModel(tmpetagere.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une étagère"),
                    QObject::tr("Etagère supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une étagère"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_idmod->text().toInt();
    QString titre= ui->lineEdit_titremod->text();
    QString auteur= ui->lineEdit_auteurmod->text();

  Livre l(id,titre,auteur);
  bool test=l.modifier(id);
  if(test)
{ui->tablivre->setModel(tmplivre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un livre"),
                  QObject::tr("Livre modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier livre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_modifier_4_clicked()
{
    int id = ui->lineEdit_idmod_2->text().toInt();
    int quantite= ui->lineEdit_quantitemod->text().toInt();
    QString etat= ui->lineEdit_etatmod->text();

  Etagere e(id,quantite,etat);
  bool test=e.modifier_4(id);
  if(test)
{ui->tabetagere->setModel(tmpetagere.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier une étagère"),
                  QObject::tr("Etagère modifiée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier étagère"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_rechercher_clicked()
{

    QString str=ui->lineEdit_rechercher->text();
    ui->tabrecherche->setModel(tmplivre.recherche(str));
}




void MainWindow::on_pb_modifier_5_clicked()
{
    QString str=ui->lineEdit_idmod_3->text();
    ui->tabrecherche2->setModel(tmpetagere.modifier_5(str));
}
