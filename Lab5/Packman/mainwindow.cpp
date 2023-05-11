#include "mainwindow.h"
#include "ui_mainwindow.h"

char MainWindow::getLetraPulse() const
{
    return letraPulse;
}

void MainWindow::setLetraPulse(char newLetraPulse)
{
    letraPulse = newLetraPulse;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(13,0,780,450);
    pcmn =new Pacman(399,255,30,nullptr);
    scene->setBackgroundBrush(Qt::black);
    crearMapa();
    scene->addItem(pcmn);
    TimepScene = new QTimer();

    TimepScene->start(50);
    TimepPoint= new QTimer();
    TimepPoint->start(100);
    connect(TimepScene,&QTimer :: timeout, this, &MainWindow::colisiones);

    connect(ui->lcdNumber, SIGNAL(overflow()), this, SLOT(on_lcdNumber_overflow()));

    //if(TotalCoins==7);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_W  && blokW==0){
        setLetraPulse('W');
        pcmn->MoveUp();
        blokA=0;
        blokS=0;
        blokD=0;
    } else if(event->key()==Qt::Key_S  && blokS==0){
        setLetraPulse('S');
        pcmn->MoveDown();
        blokA=0;
        blokW=0;
        blokD=0;
    }else if(event->key()==Qt::Key_D   && blokD==0){
        setLetraPulse('D');
        pcmn->MoveRight();
        blokA=0;
        blokS=0;
        blokW=0;
    }else if(event->key()==Qt::Key_A   && blokA==0){
        setLetraPulse('A');
        pcmn->MoveLeft();
        blokW=0;
        blokS=0;
        blokD=0;
    }
}

void MainWindow::crearMapa(void)
{
    string myText = "";
    ifstream Mundo;
    Mundo.open("mapa.txt");



    for(int i=0;getline (Mundo, myText) ;i++) {
        cout<<myText<<endl;
        for(unsigned int j=0 ; j< myText.size(); j++) Mapa[i][j]=myText[j];
    }

    Mundo.close();
   Bloque.clear();
   coins.clear();

    for(int i=0 ; i<16 ; i++){
        for(int j=0 ; j<29 ; j++){
            if(Mapa[i][j]=='+'){
                Bloque.push_back(new Muros(j*30,i*30,1));
                scene->addItem(Bloque.last());
            }
            else if(Mapa[i][j]=='c'){
                coins.push_back(new Coin(j*30,i*30));
                new Pacman(399,255,30,nullptr);
                scene->addItem(pcmn);
            }
            else if(Mapa[i][j]==' '){
                 coins.push_back(new Coin(j*30,i*30));
                 scene->addItem(coins.last());
                        }
        }
    }
}

void MainWindow::colisiones()
{
    QList<QGraphicsItem *> Colisiones = scene->collidingItems(pcmn);
    if(!Colisiones.isEmpty()){
        for(auto K:Colisiones){
            Muros *muro=dynamic_cast<Muros *>(K);
            if(muro){
                if(muro->getMuroTipe()==1 && getLetraPulse()=='A'){
                    blokA=1;
                    pcmn->setPosx(pcmn->getPosx()+1);
                }else if(muro->getMuroTipe()==1 && getLetraPulse()=='D'){
                    blokD=1;
                    pcmn->setPosx(pcmn->getPosx()-1);
                }else if(muro->getMuroTipe()==1 && getLetraPulse()=='W'){
                    blokW=1;
                    pcmn->setPosy(pcmn->getPosy()+1);
                }else if(muro->getMuroTipe()==1 && getLetraPulse()=='S'){
                    blokS=1;
                    pcmn->setPosy(pcmn->getPosy()-1);
                }
            }
            Coin *coin = dynamic_cast<Coin *>(K);
            if(coin){
                MainWindow::on_lcdNumber_overflow();
                scene->removeItem(coin);
                coins.removeOne(coin);
            }
        }
    }
}


void MainWindow::on_lcdNumber_overflow()
{
    puntuacion++;
    ui->lcdNumber->display(puntuacion);

}

