#ifndef ABILITY_H
#define ABILITY_H

#include <QMainWindow>
#include <QPushButton>
#include <QString>
#include "monster.h"
#include "pers.h"

namespace Ui {
class Ability;
}

class Ability : public QMainWindow
{
    Q_OBJECT
    bool pass[5];
    int afterbattle;

    int scrtype;

    QWidget *prebattlescr;

    bool prebat[5][2];
    int prebatcd[5][2];

    QPushButton *button[16];


    bool inbat[5];
    int inbatcd[5][4];
    QString abilityname[16];

public:
    explicit Ability(QWidget *parent = 0);

    void abilitybuy(int x, int y);

    void remap(QWidget *parent, int x);

    void battle(Pers *pers, Monster *monster,int* pdmg, int* mdmg);

    bool abilityavailable(int x, int y);




    void useprebattle(Pers *pers, Monster *monster);
    void useafterbattle(Pers *pers);



    ~Ability();

private slots:

    void on_pushButton_clicked();

    void on_b11_clicked();

    void on_b12_clicked();

    void on_b13_clicked();

    void on_b14_clicked();

    void on_b15_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b8_clicked();

    void on_b9_clicked();

    void on_b10_clicked();

private:

    void disableprebattle();
    void disableinbattle();

    void abilitynamebind();

    void renew();

    void skillsenabled();

    void useability(int x, int y);

    void cdinbattle();
    void cdprebattle();

    void showEvent(QShowEvent *event);


    void bindbuttons();

    void crepasive(int pas);
    void creprebattle(int pre);
    void creinbattle(int inb);

    void usepassive(Monster *monster, int* mdmg);
    void useinbattle(Pers *pers, Monster *monster,int* pdmg, int* mdmg);



    Ui::Ability *ui;
};

#endif // ABILITY_H
