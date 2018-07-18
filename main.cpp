#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.setStyleSheet("background-image:url(:/myMap/back.png)");
    return a.exec();
}
