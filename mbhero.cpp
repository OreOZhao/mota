#include "mbhero.h"
#include <QDialog>
#include <QLabel>
#include"block.h"
#include "hero.h"
#include "QDebug"

mbHero::mbHero()
{
    pix= new QPixmap(":/npc/duke.png");
    pix->scaledToHeight(40);
    this->setWindowFlags(Qt::Widget | Qt::FramelessWindowHint |
                        Qt::WindowSystemMenuHint | Qt::WindowStaysOnTopHint);
    mb=new QDialog();
    QLabel *mlabel=new QLabel(mb);
    mb->setStyleSheet("background-image:url(:/myMap/black.png)");
    mlabel->setText(tr("「面壁十年图破壁,难酬蹈海亦英雄!」\n\n英雄,终于等到你!我已在此等候多时\n我会助你一臂之力的!去解救公主吧!"));
    mlabel->move(50,40);
    mlabel->setStyleSheet("QLabel{color:white}");
    mb->resize(330,150);
    mb->setWindowTitle(QObject::tr("面壁人"));
}

bool mbHero::action(Hero *hero)
{
    mb->show();
    hero->setAtt(999);
    hero->setDef(999);
    emit strong();
    return true;

}
