#include "muros.h"

int Muros::getMuroTipe() const
{
    return MuroTipe;
}

void Muros::setMuroTipe(int newMuroTipe)
{
    MuroTipe = newMuroTipe;
}

Muros::Muros(int x, int y)
{
    dimx=30;
    dimy=30;
    setPos(x, y);
}

Muros::Muros(int posx, int posy, int muroT)
{
    dimx=30;
    dimy=30;
    MuroTipe=muroT;
    setPos(posx, posy);
}

QRectF Muros::boundingRect() const
{
    return QRectF(0,0,dimx,dimy);
}

void Muros::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(MuroTipe==1){

        painter->setBrush(Qt::darkGray);
        painter->drawRect(boundingRect());
    }

}

