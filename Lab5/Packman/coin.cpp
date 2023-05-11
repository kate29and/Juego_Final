#include "coin.h"

Coin::Coin(int x, int y)
{
    dimx=15;
    dimy=15;
    setPos(x, y);
}

QRectF Coin::boundingRect() const
{
    return QRectF(0,0,dimx,dimy);
}

void Coin::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

