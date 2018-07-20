#ifndef BUSINESSMAN_H
#define BUSINESSMAN_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include "hero.h"
#include "block.h"

class Block;
class Hero;

class businessMan : public QWidget,pubilc Block
{
private:
    int id,cost,addHp,addAtt,addDef,addGKey,addBKey,addRKey;
    QDilog *shop = new QDialog(this);

public:
    virtual void action(Hero *hero);

signals:

public slots:
    void buy();
};

#endif // BUSINESSMAN_H
