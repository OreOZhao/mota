#ifndef BLOCK_H
#define BLOCK_H

#include <QWidget>
#include <QGraphicsItem>

class Block : public QWidget
{
    Q_OBJECT
public:
    explicit Block(QWidget *parent = nullptr);
    QGraphicsPixmapItem *itempix;
    QPixmap *pix;
    QPointF cpos,arrivepos;
    void setPos(qreal x,qreal y);
signals:

public slots:
};

#endif // BLOCK_H
