#include "block.h"

Block::Block(QWidget *parent) : QWidget(parent)
{

}

void Block::setPos(qreal x, qreal y)
{
    cpos.setX(x);
    cpos.setY(y);
    itempix->setPos(cpos);
}
