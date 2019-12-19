#ifndef SHOP_H
#define SHOP_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class shop:public QWidget
{
    Q_OBJECT
public:
    shop();
    ~shop();
    QLabel A,B,C,D;
    QLabel welcome;
    void keyPressEvent(QKeyEvent *event);
signals:
    void pay(char);

public slots:
    void sendPayA();
    void sendPayB();
    void sendPayC();
    void closeMe();
};

#endif // SHOP_H
