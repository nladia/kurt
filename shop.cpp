#include "shop.h"
#include "ui_shop.h"

Shop::Shop(QWidget *parent, Pers *prs, bool weap, bool abil, Ability *abilit, int floorn) :
    QMainWindow(parent),
    ui(new Ui::Shop)
{
    floornum = floorn;
    ui->setupUi(this);
    pers = prs;
    map = parent;
    weapon = weap;
    ability = abil;
    abilki = abilit;
    ui->pushButton->hide();
    ui->pushButton_2->hide();

    ui->exp->setText(QString("currect exp : %1").arg(pers->expp()));

    if (ability == true) ui->pushButton_2->show();
    if (weapon == true) ui->pushButton->show();
}

Shop::~Shop()
{
    delete ui;
}

void Shop::on_pushButton_clicked()
{
    if (pers->expp() >= 15)
    {
        ui->pushButton->hide();
        pers->gexp(-15);
        Loot *lot = new Loot(map, pers, 0, floornum);
        lot->shop();
        lot->show();
        hide();

    }

}

void Shop::on_pushButton_3_clicked()
{
    map->show();
    hide();
}

void Shop::on_pushButton_2_clicked()
{
    int x, y;

    if (pers->expp() >= 40)
    {
        ui->pushButton_2->hide();
        pers->gexp(-40);
        for (int i = 0; i < 6; i++)
        {
            x=rand() % 3;
            y=rand() % 5;
            if (! abilki->abilityavailable(x,y))
            {
            abilki->abilitybuy(x, y);
            break;
            }
        }

        abilki->remap(map, 0);

        abilki->show();
        hide();
    }
}

void Shop::showEvent( QShowEvent * )
{
    ui->exp->setText(QString("currect exp : %1").arg(pers->expp()));
}
