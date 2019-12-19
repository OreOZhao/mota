#ifndef BUSINESSMAN_H
#define BUSINESSMAN_H


#include <QObject>
#include <QWidget>
#include <QDialog>
#include "hero.h"
#include "block.h"
#include "shop.h"

class Block;
class Hero;
class shop;

class businessMan :public Block
{
    Q_OBJECT
private:
    Hero *hero;
    //char choice='D';
    int id,cost,addHp,addAtt,addDef,addGKey,addBKey,addRKey;

public:
    shop s;
    businessMan(int);//initial with business man id
    bool action(Hero *hero);//hezitated from block|| a virtual function

public slots:

    void buy(char choice);

};


#endif // BUSINESSMAN_H
