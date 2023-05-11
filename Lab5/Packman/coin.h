#ifndef COIN_H
#define COIN_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>

using namespace std;

class Coin : public QGraphicsItem
{
    int posx, posy;
    int dimx, dimy;
public:
    Coin(int, int );
    virtual QRectF boundingRect() const;
    virtual void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);
};

#endif // COIN_H
