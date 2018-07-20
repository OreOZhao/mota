#include <QPushButton>
#include <QLabel>
#include "businessman.h"
#include "hero.h"

using namespace QObject;

businessMan::businessMan(int num)
{
    id = num;
    QPushButton A(shop),B(shop),C(shop),D(shop);
    A.resize();B.resize();C.resize();D.resize();
    A.move();B.move();C.move();D.move();
    D.setText(tr"退出商店");
    QLabel welcome(this);
    welcome.setText(tr"欢迎选购，我的勇士！");

    switch (id) {
    case 1:
        A.setText(tr"增加800点生命           ￥25");
        B.setText(tr"增加5点攻击力            ￥25");
        C.setText(tr"增加5点防御             ￥25");
        cost=25;addHp=800;addAtt=5;addDef=5;addGKey=0;addBKey=0;addRKey=0;
        pix= new QPixmap("");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 2:
        A.setText(tr"增加2400点生命            ￥75");
        B.setText(tr"增加15点攻击力            ￥75");
        C.setText(tr"增加15点防御              ￥75");
        cost=75;addHp=2400;addAtt=15;addDef=15;addGKey=0;addBKey=0;addRKey=0;
        pix= new QPixmap("");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    case 3:
        A.setText(tr"绿钥匙1把            ￥10");
        B.setText(tr"蓝钥匙1把            ￥50");
        C.setText(tr"红钥匙1把            ￥100");

        pix= new QPixmap("");
        pix->scaledToHeight(40);
        this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                           Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
        break;
    }

    connect(&A,&QPushButton::pressed,this,&businessMan::buy);
    connect(&B,&QPushButton::pressed,this,&businessMan::buy);
    connect(&C,&QPushButton::pressed,this,&businessMan::buy);
    connect(&D,&QPushButton::pressed,this,&businessMan::close);

}

businessMan::action(Hero *hero){
    shop->show();
}

businessMan::buy(){

}
