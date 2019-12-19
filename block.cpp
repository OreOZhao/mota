#include "block.h"

Block::Block(QWidget *parent) : QWidget(parent)
{
    pix= new QPixmap(":/brick/brick.png");
    pix->scaledToHeight(40);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                         Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
}

void Block::setPos(qreal x, qreal y)
{
    cpos.setX(x);
    cpos.setY(y);
    itempix->setPos(cpos);
}

bool Block::action(Hero *hero)
{
    return true;
}

void Block::setXY(int a,int b)
{
    int x=a*40+240;
    int y=b*40+40;
    setPos(x,y);
}
