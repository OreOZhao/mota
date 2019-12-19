#ifndef PROP_H
#define PROP_H

#include "widget.h"
#include "block.h"
#include "hero.h"

class Block;
class Hero;

class Prop:public Block
{
private:
    int id=0,addAtt=0,addDef=0,addHp=0,addGKey=0,addBKey=0,addRKey=0;
public:
    Prop(int num);
    bool action(Hero *hero);
};

#endif // PROP_H
