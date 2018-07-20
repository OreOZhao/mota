#ifndef BUSINESSMAN_H
#define BUSINESSMAN_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include "hero.h"
#include "block.h"

class Block;
class Hero;

class businessMan :public Block
{
private:
    Hero *hero;
    int id,cost,addHp,addAtt,addDef,addGKey,addBKey,addRKey;
    QDialog *shop = new QDialog(this);

public:
    businessMan(int);//initial with business man id
    virtual void action(Hero *hero);//hezitated from block|| a virtual function

signals:

public slots:
    void buyA();
    void buyB();
    void buyC();

};

#endif // BUSINESSMAN_H
