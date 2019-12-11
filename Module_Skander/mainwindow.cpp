#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employees.h"
#include "programme.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ui->tabemployees->setModel(tmpemployees.afficher());
ui->tab_prog->setModel(tmpprogramme.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int Employee_ID = ui->lineEdit_id->text().toInt();
    QString Nom= ui->lineEdit_nom->text();
    QString Prenom= ui->lineEdit_prenom->text();
    int CIN= ui->lineEdit_CIN->text().toInt();

    QString Email= ui->lineEdit_Email->text();
    int Num_Tel= ui->lineEdit_Tel->text().toInt();
    QString Adresse= ui->lineEdit_Adresse->text();
    QString Grade= ui->comboBox->currentText();
    QString Fonction= ui->comboBox_2->currentText();
    int Prog_iD= ui->lineEdit_Prog_ID->text().toInt();
  Employees e(Employee_ID,Nom,Prenom,CIN,Email,Num_Tel,Adresse,Grade,Fonction,Prog_iD);
  bool test=e.ajouter();
  if(test)
{ui->tabemployees->setModel(tmpemployees.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Employé"),
                  QObject::tr("Employé ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un Employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpemployees.supprimer(id);
if(test)
{ui->tabemployees->setModel(tmpemployees.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Employé supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_ajouter_2_clicked()
{
    int Prog_ID= ui->lineEdit_ProgID->text().toInt();
    QString Poste= ui->comboBox_3->currentText();
    QString Section= ui->comboBox_4->currentText();
    Programme p(Prog_ID,Poste,Section);
    bool test=p.ajouter();
    if(test)
  {ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
  QMessageBox::information(nullptr, QObject::tr("Ajouter un Programme"),
                    QObject::tr("Programme ajouté.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un Programme"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    int id = ui->lineEdit_id_4->text().toInt();
    bool test=tmpprogramme.supprimer(id);
    if(test)
    {ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un programme"),
                    QObject::tr("Programme supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un programme"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_rechercher_clicked()
{
    QString id = ui->lineEdit_id_R->text();
    ui->tabemployees_3->setModel(tmpemployees.recherche(id));
}

void MainWindow::on_pb_ajouter_6_clicked()
{
    int Employee_ID = ui->lineEdit_id_10->text().toInt();
    QString Nom= ui->lineEdit_nom_4->text();
    QString Prenom= ui->lineEdit_prenom_4->text();
    int CIN= ui->lineEdit_CIN_4->text().toInt();

    QString Email= ui->lineEdit_Email_4->text();
    int Num_Tel= ui->lineEdit_Tel_5->text().toInt();
    QString Adresse= ui->lineEdit_Adresse_5->text();
    QString Grade= ui->comboBox_11->currentText();
    QString Fonction= ui->comboBox_12->currentText();
    int Prog_iD= ui->lineEdit_Prog_ID_5->text().toInt();
  Employees e(Employee_ID,Nom,Prenom,CIN,Email,Num_Tel,Adresse,Grade,Fonction,Prog_iD);
  bool test=e.modifier(Employee_ID);
  if(test)
{ui->tabemployees->setModel(tmpemployees.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier Employé"),
                  QObject::tr("Employé modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier Employé"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_ajouter_7_clicked()
{
    int Prog_ID = ui->lineEdit_ProgID_2->text().toInt();
    QString Poste= ui->comboBox_13->currentText();
    QString Section= ui->comboBox_14->currentText();

  Programme p(Prog_ID,Poste,Section);
  bool test=p.modifier(Prog_ID);
  if(test)
{ui->tab_prog->setModel(tmpprogramme.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier Programme"),
                  QObject::tr("Programme modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier Programme"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
