#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employees.h"
#include "programme.h"
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

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_supprimer_2_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_ajouter_6_clicked();

    void on_pb_ajouter_7_clicked();

private:
    Ui::MainWindow *ui;
    Employees tmpemployees;
    Programme tmpprogramme;
};

#endif // MAINWINDOW_H
