#include <QPushButton>
#include <QLabel>
#include "businessman.h"
#include "hero.h"

businessMan::businessMan(int num)
{
    id = num;

    /*
     * 1 primary business man
     * 2 senior business man
     * 3 key seller
     */

    QPushButton A(shop),B(shop),C(shop),D(shop);
    /*
    A.resize();B.resize();C.resize();D.resize();
    A.move();B.move();C.move();D.move();
    */
    D.setText(QObject::tr("退出商店"));
    QLabel welcome(this);
    welcome.setText(QObject::tr("欢迎选购，我的勇士！"));

    switch (id) {
    case 1:
        A.setText(QObject::tr("增加800点生命           ￥25"));
        B.setText(QObject::tr("增加5点攻击力            ￥25"));
        C.setText(QObject::tr("增加5点防御             ￥25"));
        cost=25;addHp=800;addAtt=5;addDef=5;addGKey=0;addBKey=0;addRKey=0;
        pix= new QPixmap("");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 2:
        A.setText(QObject::tr("增加2400点生命            ￥75"));
        B.setText(QObject::tr("增加15点攻击力            ￥75"));
        C.setText(QObject::tr("增加15点防御              ￥75"));
        cost=75;addHp=2400;addAtt=15;addDef=15;addGKey=0;addBKey=0;addRKey=0;
        pix= new QPixmap("");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 3:
        A.setText(QObject::tr("绿钥匙1把            ￥10"));
        B.setText(QObject::tr("蓝钥匙1把            ￥50"));
        C.setText(QObject::tr("红钥匙1把            ￥100"));

        pix= new QPixmap("");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    }

    connect(&A,&QPushButton::pressed,this,&businessMan::buyA);
    connect(&B,&QPushButton::pressed,this,&businessMan::buyB);
    connect(&C,&QPushButton::pressed,this,&businessMan::buyC);
    connect(&D,&QPushButton::pressed,this,&businessMan::close);

}

void businessMan::action(Hero *h){//hezitated from block|| a virtual function
    hero=h;
    shop->show();
}

void businessMan::buyA(){//choose A
    if(id == 3) cost=10;//initial key cost
    if(hero->getMoney() < cost) return;
     else{
        hero->setLife(hero->getLife()+addHp);
        hero->setGKey(hero->getGKey()+addGKey);
        hero->setMoney(hero->getMoney()-cost);
    }
}

void businessMan::buyB(){//choose B
    if(id == 3) cost=50;//initial key cost
    if(hero->getMoney() < cost) return;
     else{
        hero->setAtt(hero->getAtt()+addAtt);
        hero->setBKey(hero->getBKey()+addBKey);
        hero->setMoney(hero->getMoney()-cost);
    }
}

void businessMan::buyC(){//choose C
    if(id == 3) cost=100;//initial key cost
    if(hero->getMoney() < cost) return;
    else{
        hero->setDef(hero->getDef()+addDef);
        hero->setRKey(hero->getRKey()+addRKey);
        hero->setMoney(hero->getMoney()-cost);
    }
}
