#include "widget.h"
#include <QApplication>
#include "start.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Start s;
    if(s.exec()==QDialog::Accepted){
        Widget w;
        w.show();
        w.setStyleSheet("background-image:url(:/myMap/back.png)");
        return a.exec();
    }
    else return 0;
}
