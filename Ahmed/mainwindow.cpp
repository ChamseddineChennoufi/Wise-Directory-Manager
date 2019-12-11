
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "commande.h"
#include <QMessageBox>
#include "qcustomplot.h"
#include <QLabel>
#include<QSystemTrayIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
QPixmap bg("C:/Users/novacomputer/Desktop/projet 2A/build-Atelier_Crud_Vf-Desktop_Qt_5_13_1_MinGW_32_bit-Debug/WLMbackground.jpg");
ui->BG->setPixmap(bg);
ui->tabfour->setModel(tmpfour.afficher());
ui->tabc->setModel(tmpcom.afficher_commande());
ui->tabc_2->setModel(tmpcom.afficher_commande_trier());
ui->tablecalcul->setModel(tmpcom.calcul_quantite());
//*MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom_societe= ui->lineEdit_nom_societe->text();
    QString adresse= ui->lineEdit_adresse->text();
    long numtel=ui->lineEdit_numtel->text().toInt();
  fournisseur f(id,nom_societe,adresse,numtel);
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

void MainWindow::on_pb_supprimer_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpfour.supprimer(id);
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

void MainWindow::on_ajouterc_clicked()
{
    int reference = ui->lineEdit_ref->text().toInt();
    QString datec= ui->lineEdit_datec->text();
    int quantite=ui->lineEdit_quan->text().toInt();
    QString nom_commande=ui->lineEdit_nomc_2->text();
    int id=ui->lineEdit_idd->text().toInt();
  commande c(reference,datec,quantite,nom_commande,id);
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



void MainWindow::on_supprimerc_clicked()
{
    int reference = ui->lineEdit_4->text().toInt();
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
void MainWindow::on_PushButton_Edit_clicked()
{
    int id = ui->lineEdit_ide->text().toInt();
    QString nom_societe= ui->lineEdit_nom_societe_2->text();
    QString adresse= ui->lineEdit_adresse_2->text();
    int numtel=ui->lineEdit_numtel_2->text().toInt();
    fournisseur f1(id,nom_societe,adresse,numtel);
  bool test=f1.modifier(id);
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



void MainWindow::on_pushButton_clicked()
{

    int reference = ui->lineEdit_ref_2->text().toInt();
    QString datec= ui->lineEdit_d->text();
    int quantite=ui->lineEdit_3->text().toInt();
    QString nom_commande= ui->lineEdit_nomc->text();
    int id=ui->lineEdit_iddd->text().toInt();
    commande c1(reference,datec,quantite,nom_commande,id);
  bool test=c1.modifier_commande(reference);
  if(test)
{ui->tabc->setModel(tmpcom.afficher_commande());
      ui->tabc_2->setModel(tmpcom.afficher_commande_trier());//refresh
      ui->tablecalcul->setModel(tmpcom.calcul_quantite());
QMessageBox::information(nullptr, QObject::tr("modifier une commande"),
                  QObject::tr("modifier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else

      QMessageBox::critical(nullptr, QObject::tr("modifier une commande"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_pb_rechercher_clicked()
{
    QString str=ui->lineEdit_rechercher->text();
    ui->tabrecherche->setModel(tmpfour.recherche(str));
}
void MainWindow::makePlot()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));

    // create empty bar chart objects:
    //QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    //QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
   // regen->setAntialiased(false); // gives more crisp, pixel aligned bar borders
   // nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
   // regen->setStackingGap(1);
   // nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // set names and colors:
    fossil->setName("Nombre des commandes");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    /*nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));*/
    // stack bars on top of each other:
   // nuclear->moveAbove(fossil);
   // regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7<<8<<9<<10<<11<<12;
    labels << "1.1" << "2.1" << "3.1" << "4.1" << "5.1" << "6.1" << "7.1"<< "8.1" << "9.1" << "10.1" << "11.1" << "12.1";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);
    ui->customPlot->xAxis->setTickLabelRotation(60);
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 7);
    ui->customPlot->xAxis->setRange(0, 14);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 12.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Nombre des commandes \n par % datec (2019)");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData;
    fossilData=tmpcom.stat();
    fossil->setData(ticks, fossilData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
