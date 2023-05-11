#include "pacman.h"

int Pacman::getPosx() const
{
    return posx;
}

void Pacman::setPosx(int newPosx)
{
    posx = newPosx;
}

int Pacman::getPosy() const
{
    return posy;
}

void Pacman::setPosy(int newPosy)
{
    posy = newPosy;
}

int Pacman::getVelocidad() const
{
    return velocidad;
}

void Pacman::setVelocidad(int newVelocidad)
{
    velocidad = newVelocidad;
}

void Pacman::MinMax(int num)
{
    switch (num) {
    case 1:
        minimo=0;
        maximo=90;
        columnas=minimo;
    break;
    case 2:
        minimo=120;
        maximo=180;
        columnas=minimo;
    break;
    case 3:
        minimo=210;
        maximo=270;
        columnas=minimo;
    break;
    case 4:
        minimo=300;
        maximo=360;
        columnas=minimo;
    break;

    }
}

Pacman::Pacman(int x, int y, int r, QObject *parent)
{
    this->posx=x;
    this->posy=y;
    this->radio=r; // es igual a tner los metodos de ingreso.

    setPos(posx,posy);

    timer =new QTimer();
    filas =0;
    columnas =0;
    pixmap= new QPixmap(":/imagenes/pacman.png");

    ancho =30;
    alto = 30;

    timer->start(150);

    connect(timer, &QTimer :: timeout, this, &Pacman::Actualizar);

}

QRectF Pacman::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2,ancho,alto);
}

void Pacman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap,columnas,0,ancho,alto);
}


void Pacman::MoveUp()
{
   posy-=velocidad;
   setPos(posx, posy);
   MinMax(1);
   qDebug()<<posy<<"posicion en y actual\n";
}

void Pacman::MoveDown()
{
    posy+=velocidad;
    setPos(posx, posy);
    MinMax(2);
    qDebug()<<posy<<"posicion en y actual\n";
}

void Pacman::MoveLeft()
{
    posx-=velocidad;
    setPos(posx, posy);
    MinMax(3);
    qDebug()<<posx<<"posicion en x actual\n";
}

void Pacman::MoveRight()
{
    posx+=velocidad;
    setPos(posx, posy);
    MinMax(4);
    qDebug()<<posx<<"posicion en x actual\n";
}

void Pacman::Actualizar()
{
    columnas +=30;
    if(columnas==maximo)
        columnas=minimo;

    this->update(-ancho/2, -alto/2, ancho, alto);
}


