#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QGraphicsPixmapItem>

class Hero;

class Block : public QWidget
{
    Q_OBJECT
public:
    explicit Block(QWidget *parent = nullptr);
    int floor;
    int x;
    int y;
    QGraphicsPixmapItem *itempix;
    QPixmap *pix;
    QPointF cpos;
    void setPos(qreal x,qreal y);
    void setXY(int a,int b);
    virtual bool action(Hero *hero );
    //true :stay ;false :clear
signals:
public slots:
};

#endif // BLOCK_H
