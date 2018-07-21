#ifndef HERO_H
#define HERO_H

#include <QMainWindow>
#include <QWidget>
#include "info.h"
#include "widget.h"
#include <QGraphicsPixmapItem>
#include <block.h>

extern int currentF;

class Hero : public QWidget
{

    Q_OBJECT
public:
    explicit Hero(QWidget *parent = nullptr);
    QGraphicsPixmapItem *itempix;
    QPixmap *pix;
    void copyHero(Hero *hero);

    /*------keys------*/
    void setRKey(int r){redKey=r;}
    void setGKey(int g){goldKey=g;}
    void setBKey(int b){blueKey=b;}
    int getRKey(){return redKey;}
    int getGKey(){return goldKey;}
    int getBKey(){return blueKey;}
    /*------attack&defence------*/
    void setAtt(int a){attackVal=a;}
    void setDef(int d){defenceVal=d;}
    void setExp(int e){experVal=e;}
    int getAtt(){return attackVal;}
    int getDef(){return defenceVal;}
    int getExp(){return experVal;}
    /*------level------*/
    void setLevel(int l){solLevel=l;}
    int getLevel(){return solLevel;}
    /*------life------*/
    void setLife(int l){lifeVal=l;}
    int getLife(){return lifeVal;}
    /*------money------*/
    void setMoney(int m){moneyVal=m;}
    int getMoney(){return moneyVal;}
    /*------position------*/
    void setPos(qreal x,qreal y);
    void setXY(int a,int b);
    QPointF cpos,arrivepos;
    int getFloor(){return floor;}
    void setFloor(int f){floor=f;}
    /*------block------*/
    void fight(Block& monster);
    void buy(Block& busiman);
    void pick(Block &prop);
private:
    int redKey=0;
    int goldKey=0;
    int blueKey=0;
    int moneyVal=0;
    int experVal=0;
    int attackVal=10;
    int defenceVal=10;
    int solLevel=1;
    int lifeVal=10000;
    int floor=currentF;
signals:
    void pkSignal();
    void buySignal();
    void pickSignal();
public slots:

};

#endif // HERO_H
