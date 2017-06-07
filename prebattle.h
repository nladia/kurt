#ifndef PREBATTLE_H
#define PREBATTLE_H

#include <QMainWindow>

namespace Ui {
class Prebattle;
}

class Prebattle : public QMainWindow
{
    Q_OBJECT
    QWidget *map;
    Pers *pers;
    int floor;
    Floor *floor;

public:
    explicit Prebattle(QWidget *mp = 0, Pers *prs = 0,int x = 0, int flor = 0);
    void enter();
    ~Prebattle();

private:
    Ui::Prebattle *ui;
};

#endif // PREBATTLE_H
