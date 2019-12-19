#include "businessman.h"
#include <QPushButton>
#include <QLabel>
#include "hero.h"
#include <QHBoxLayout>
#include <QDebug>
#include "shop.h"

businessMan::businessMan(int num)
{
    id = num;

    /*
     * 1 primary business man
     * 2 senior business man
     * 3 key seller
*/

    //QPushButton A(shop),B(shop),C(shop),D(shop);
    /*
    A.resize();B.resize();C.resize();D.resize();*/
    //A.move(10,10);B.move(10,30);C.move(10,50);D.move(10,70);

   // D.setText(QObject::tr("退出商店"));
    //QLabel welcome(this);
    // welcome.setText(QObject::tr("欢迎选购，我的勇士！"));

    switch (id) {
    case 1:
        s.A.setText(QObject::tr("1.增加800点生命            ￥25"));
        s.B.setText(QObject::tr("2.增加5点攻击力            ￥25"));
        s.C.setText(QObject::tr("3.增加5点防御                ￥25"));
        cost=25;addHp=800;addAtt=5;addDef=5;addGKey=0;addBKey=0;addRKey=0;
        pix= new QPixmap(":/npc/origin.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 2:
        s.A.setText(QObject::tr("1.增加2400点生命            ￥75"));
        s.B.setText(QObject::tr("2.增加15点攻击力            ￥75"));
        s.C.setText(QObject::tr("3.增加15点防御              ￥75"));
        cost=75;addHp=2400;addAtt=15;addDef=15;addGKey=0;addBKey=0;addRKey=0;
        pix= new QPixmap(":/npc/steam.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 3:
        s.A.setText(QObject::tr("1.金钥匙1把            ￥10"));
        s.B.setText(QObject::tr("2.蓝钥匙1把            ￥50"));
        s.C.setText(QObject::tr("3.红钥匙1把            ￥100"));
        addHp=0;addAtt=0;addDef=0;addGKey=1;addBKey=1;addRKey=1;
        pix= new QPixmap(":/npc/battlenet.png");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    }

    connect(&this->s,SIGNAL(pay(char)),this,SLOT(buy(char)));
    //connect(&this->s,&shop::pay,this,&businessMan::buy);
   // connect(&this->s,&shop::pay,this,&businessMan::buy);
}

bool businessMan::action(Hero *h){//hezitated from block|| a virtual function
    hero=h;
    s.show();
    return true;

}

void businessMan::buy(char choice){
    switch (choice) {
    case 'A':
        if(id == 3) cost=10;//initial key cost
        if(hero->getMoney() < cost) return;
         else{
            hero->setLife(hero->getLife()+addHp);
            hero->setGKey(hero->getGKey()+addGKey);
            hero->setMoney(hero->getMoney()-cost);
        }
        break;

    case 'B':
        if(id == 3) cost=50;//initial key cost
        if(hero->getMoney() < cost) return;
         else{
            hero->setAtt(hero->getAtt()+addAtt);
            hero->setBKey(hero->getBKey()+addBKey);
            hero->setMoney(hero->getMoney()-cost);
        }
        break;
    case 'C':
        if(id == 3) cost=100;//initial key cost
        if(hero->getMoney() < cost) return;
        else{
            hero->setDef(hero->getDef()+addDef);
            hero->setRKey(hero->getRKey()+addRKey);
            hero->setMoney(hero->getMoney()-cost);
        }
        break;
    default:
        //qDebug<<"something warong";
        break;
    }
}
