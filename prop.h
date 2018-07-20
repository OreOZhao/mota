#ifndef PROP_H
#define PROP_H
#include "block.h"

class Prop:public Block
{
private:
    int id=0,addAtt=0,addDef=0,addHp=0,addGKey=0,addBKey=0,addRKey=0;
public:
    Prop(int num);
    virtual void action(Hero *hero);
};

#endif // PROP_H
