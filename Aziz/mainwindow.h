#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "abonnement.h"
#include "abonnes.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();
    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_clicked();
    void on_pb_supprimer_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Rechercher_clicked();

private:
    Ui::MainWindow *ui;
    Abonnement tmpabonnement;
    abonnes tmpabonnes ;
};

#endif // MAINWINDOW_H
