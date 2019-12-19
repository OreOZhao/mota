#include "princess.h"
#include<QDialog>
#include <QLabel>

Princess::Princess()
{
    pix= new QPixmap(":/npc/princess.png");
    pix->scaledToHeight(40);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                        Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    pri=new QDialog();
    QLabel *plabel=new QLabel(pri);
    pri->setStyleSheet("background-image:url(:/myMap/black.png)");
    plabel->setText(tr("邪恶的妖王，终于灭亡了。\n公主从黑塔中走出，于是万物复苏 ，\n百花争艳，蝴蝶翩翩，生气重回幻想王国。\n从此，人们过着安定的生活。\n而英雄，因救万民有功，而入天国，成为神界的战士。\n此刻， 他正在天国的某处,笑望他的国家"));
    plabel->move(50,20);
    plabel->setStyleSheet("QLabel{color:white}");
    pri->resize(400,150);

}

bool Princess::action(Hero *hero)
{
    pri->show();
    return true;
}
