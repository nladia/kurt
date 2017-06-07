#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QPushButton>
#include "floor.h"
#include "shop.h"
#include "ability.h"


namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT
    Floor *floor;
    Pers *pers;
    Ability *ability;
    QWidget *par;
    Shop *shop;
    int floornum;
    QPushButton *button[31];
    int clear;

public:
    explicit Map(QWidget *parent = 0, Pers *prs = 0);
    void hiden();
    ~Map();

private slots:
    void bindbuttons();

    void showEvent(QShowEvent * event);

    void simplebutton(int i);

    void on_pushButton_31_clicked();

    void on_b8_clicked();

    void on_b3_clicked();

    void on_b14_clicked();

    void on_b9_clicked();

    void on_b4_clicked();

    void on_b12_clicked();

    void on_b11_clicked();

    void on_b17_clicked();

    void on_start_clicked();

    void on_b1_clicked();

    void on_b2_clicked();

    void on_b5_clicked();

    void on_b6_clicked();

    void on_b7_clicked();

    void on_b10_clicked();

    void on_b15_clicked();

    void on_b16_clicked();

    void on_b18_clicked();

    void on_b19_clicked();

    void on_b20_clicked();

    void on_b21_clicked();

    void on_b22_clicked();

    void on_b23_clicked();

    void on_b24_clicked();

    void on_b25_clicked();

    void on_b26_clicked();

    void on_b27_clicked();

    void on_b28_clicked();

    void on_b29_clicked();

    void on_b30_clicked();

    void on_shop_clicked();

private:
    Ui::Map *ui;
};

#endif // MAP_H
