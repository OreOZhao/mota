#ifndef START_H
#define START_H

#include <QDialog>

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

public:
    explicit Start(QWidget *parent = 0);
    ~Start();

private:
    Ui::Start *ui;
};

#endif // START_H
