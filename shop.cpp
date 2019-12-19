#include "shop.h"

#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QDebug>

shop::shop(){

    this->setWindowTitle(QObject::tr("商店"));
    this->resize(250,150);
    A.setParent(this);
    B.setParent(this);
    C.setParent(this);
    D.setParent(this);
    A.move(15,20);
    B.move(15,50);
    C.move(15,80);
    D.move(15,110);
    D.setText(QObject::tr("4.退出商店"));
    welcome.setParent(this);
    welcome.setText(QObject::tr("欢迎选购，我的勇士！\n"));
    welcome.move(5,5);
    welcome.show();

/*
    connect(&this->A,&QPushButton::released,this,&shop::sendPayA);
    connect(&this->B,&QPushButton::released,this,&shop::sendPayB);
    connect(&this->C,&QPushButton::released,this,&shop::sendPayC);
    connect(&this->D,&QPushButton::released,this,&shop::closeMe);
    */
}

shop::~shop()
{

}

void shop::sendPayA(){
    emit pay('A');
    this->A.setFocusPolicy(Qt::NoFocus);
    this->B.setFocusPolicy(Qt::NoFocus);
    this->C.setFocusPolicy(Qt::NoFocus);
    this->D.setFocusPolicy(Qt::NoFocus);
    this->setFocusPolicy(Qt::NoFocus);
}
void shop::sendPayB(){
    emit pay('B');
    this->A.setFocusPolicy(Qt::NoFocus);
    this->B.setFocusPolicy(Qt::NoFocus);
    this->C.setFocusPolicy(Qt::NoFocus);
    this->D.setFocusPolicy(Qt::NoFocus);
    this->setFocusPolicy(Qt::NoFocus);
}
void shop::sendPayC(){
    emit pay('C');
    this->A.setFocusPolicy(Qt::NoFocus);
    this->B.setFocusPolicy(Qt::NoFocus);
    this->C.setFocusPolicy(Qt::NoFocus);
    this->D.setFocusPolicy(Qt::NoFocus);
    this->setFocusPolicy(Qt::NoFocus);
}
void shop::closeMe()
{
    emit pay('D');
    this->A.setFocusPolicy(Qt::NoFocus);
    this->B.setFocusPolicy(Qt::NoFocus);
    this->C.setFocusPolicy(Qt::NoFocus);
    this->D.setFocusPolicy(Qt::NoFocus);
    this->close();
    this->setFocusPolicy(Qt::NoFocus);
}
void shop::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_1:
        sendPayA();
        break;
    case Qt::Key_2:
        sendPayB();
        break;
    case Qt::Key_3:
        sendPayC();
        break;
    case Qt::Key_4:
        closeMe();
        break;
    default:
        closeMe();
        break;
    }
}
