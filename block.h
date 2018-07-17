#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QGraphicsPixmapItem>
#include"hero.h"

class Block : public QWidget
{
    Q_OBJECT
public:
   virtual void Action(Hero&)=0;
   void Block::setPos(qreal x, qreal y);
   explicit Block(QWidget *parent = nullptr);
   QGraphicsPixmapItem *itempix;
   QPixmap *pix;
   QPointF cpos;
   void setPos(qreal x,qreal y);
signals:

public slots:
};

#endif // BLOCK_H
