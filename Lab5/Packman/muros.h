#ifndef MUROS_H
#define MUROS_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>
#include <QPixmap>

using namespace std;

class Muros : public QGraphicsItem
{
    int posx, posy;
    int dimx, dimy;
    int MuroTipe;

public:
    Muros(int, int );
    Muros(int , int , int );
    virtual QRectF boundingRect() const;
    virtual void paint(
            QPainter *painter,
            const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);
    int getMuroTipe() const;
    void setMuroTipe(int newMuroTipe);
};

#endif // MUROS_H
