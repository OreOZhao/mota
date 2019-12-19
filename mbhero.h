#ifndef MBHERO_H
#define MBHERO_H


#include"block.h"

class mbHero : public Block
{
    Q_OBJECT
public:
    mbHero();
    bool action(Hero*hero);
private:
    QDialog*mb;
signals:
    void strong();
};

#endif // MBHERO_H
