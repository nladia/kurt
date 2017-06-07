#ifndef LOOT_H
#define LOOT_H

#include <QMainWindow>
#include "room.h"

namespace Ui {
class Loot;
}

class Loot : public QMainWindow
{
    Q_OBJECT
    Pers *pers;
    QWidget *par;
    Weapon *weap;
    int exp;
    int floornum;

public:
    explicit Loot(QWidget *parent, Pers *persb, int ex , int floorn);
    void shop();
    ~Loot();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Loot *ui;
};

#endif // LOOT_H
