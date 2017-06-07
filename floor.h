#ifndef FLOOR_H
#define FLOOR_H

#include <QMainWindow>
#include "roombattle.h"

namespace Ui {
class Floor;
}

class Floor : public QMainWindow
{
    Q_OBJECT
    QWidget *map;
    RoomBattle *r1;
    RoomBattle *r2;
    RoomBattle *r3;
    RoomBattle *r4;
    RoomBattle *r5;
    RoomBattle *r6;
    RoomBattle *r7;
    RoomBattle *r8;
    RoomBattle *r9;
    RoomBattle *r10;
    Pers *pers;
    Ability *ability;
    int rom1[30][2];
    int floor;
    int num;

public:
    int enter(int);
    bool alive(int);


    Floor(QWidget *mp = 0, Pers *prs = 0, int flor = 0, Ability *abil = 0);
    bool exist(int);
    void floor1();
    void createfloor();
    ~Floor();

private slots:
    void showEvent ( QShowEvent * event);
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Floor *ui;
};

#endif // FLOOR_H
