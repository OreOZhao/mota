#ifndef MONSTER_H
#define MONSTER_H

#include <block.h>

class Monster:public Block
  {
  public:

     Monster(int,int,int,int,int);
     void action(Hero *hero );
 private:
     int life,attack,defence,money,experience;
  };

#endif // MONSTER_H
