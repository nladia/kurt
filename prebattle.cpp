#include "prebattle.h"
#include "ui_prebattle.h"

Prebattle::Prebattle(QWidget *mp, Pers *prs, int x, int flor) :
    QMainWindow(parent),
    ui(new Ui::Prebattle)
{
    ui->setupUi(this);

    map = mp;
    pers = prs;
    floor = flor;
    if (x == 1) ;
}

Prebattle::~Prebattle()
{
    delete ui;
}

void enter()
{

}
