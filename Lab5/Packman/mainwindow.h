#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QKeyEvent>
#include <QVector>
#include <QList>
#include <fstream>
#include <string.h>
#include <iostream>
#include "pacman.h"
#include "muros.h"
#include "coin.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int blokW=0;
    int blokS=0;
    int blokA=0;
    int blokD=0;
    char letraPulse;



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void crearMapa(void);
    char Mapa[16][29];
    QVector<Muros *> Bloque;
    QVector<Coin *> coins;
    QTimer *TimepScene;
    QTimer *TimepPoint;

    char getLetraPulse() const;
    void setLetraPulse(char newLetraPulse);

public slots:
    void colisiones(void);

private slots:
    void on_lcdNumber_overflow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Pacman *pcmn;
    int puntuacion=0;
    void keyPressEvent(QKeyEvent * event);




};
#endif // MAINWINDOW_H
