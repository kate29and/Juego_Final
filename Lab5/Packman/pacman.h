#ifndef PACMAN_H
#define PACMAN_H

#include <QDebug>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QTimer>

class Pacman: public QObject ,public QGraphicsItem
{
    Q_OBJECT

    int posx, posy, radio, velocidad=3;
    int maximo, minimo;

    void MinMax( int );

public:
    explicit Pacman(int x, int y , int r , QObject *parent = nullptr);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    QTimer *timer;
    QPixmap *pixmap;

    float filas, columnas;
    float ancho , alto;

    int getPosx() const;
    void setPosx(int newPosx);

    int getPosy() const;
    void setPosy(int newPosy);

    int getVelocidad() const;
    void setVelocidad(int newVelocidad);

    virtual QRectF boundingRect() const;

    virtual void paint(
        QPainter *painter,
        const QStyleOptionGraphicsItem *option,
        QWidget *widget = nullptr);


signals:

public slots:

    void Actualizar();
};

#endif // PACMAN_H
