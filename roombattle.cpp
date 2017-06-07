#include "roombattle.h"
#include "ui_roombattle.h"


RoomBattle::RoomBattle(QWidget *parent, int x, Pers *persb, int floor, Ability *abil) :
    QMainWindow(parent),
    ui(new Ui::RoomBattle)
{
    floornum = floor;
    ability = abil;
    pers = persb;
    ui->setupUi(this);
    par = parent;
    roomh = new Room(x, persb, floor, ability);
    firstturn = true;
    win = 0;
    renew();
}

RoomBattle::~RoomBattle()
{
    delete ui;
}

void RoomBattle::on_pushButton_clicked()
{
    if (win == 1)
        {
            this->winloot();
        }
    if (win == -1)
        {
        Looser *l = new Looser(this);
        l->show();
        hide();
        }
    if (win == 0)
    {
        win = roomh->battle();
        renew();

        if (win == 1)
        {
            ui->pushButton_2->hide();
            ui->pushButton->setText("Победа");
        }

        if (win == -1)
        {
            ui->pushButton_2->hide();
            ui->pushButton->setText("Ну бывает");
        }
    }
}
void RoomBattle::on_pushButton_2_clicked()
{
    ability->remap(this, 2);
    ability->show();
    hide();

}

void RoomBattle::winloot()
{

     ability->useafterbattle(pers);

    if (ability->abilityavailable(0,2))
    {
        roomh->pers->gexp(roomh->monstr->gexp() / 3);
        roomh->pers->gexp(roomh->monstr->gexp());



        Loot *lot = new Loot(par, pers, roomh->monstr->gexp() + roomh->monstr->gexp() / 3, floornum);
        lot->show();
        hide();
    }
    else
    {
        roomh->pers->gexp(roomh->monstr->gexp());



        Loot *lot = new Loot(par, pers, roomh->monstr->gexp(),floornum);
        lot->show();
        hide();
    }
}

bool RoomBattle::alive()
{
    return roomh->alive;
}

void RoomBattle::renew()
{
    ui->monster_hp->setText(QString("HP : %1").arg(roomh->monstr->hpp()));
    ui->pers_hp->setText(QString("HP : %1 / %2").arg(pers->hpp()).arg(pers->maxhpp()));
    ui->mdmg->setText(QString("Damage : %1").arg(roomh->attkm()));
    ui->Pdmg->setText(QString("Damage : %1").arg(roomh->attkp()));
    ui->Roll->setText(QString("Roll : %1").arg(roomh->roll()));
    ui->maxatk->setText(QString("MaxAttk : %1").arg(roomh->monstr->maxattk()));
    ui->Minatk->setText(QString("MinAttk : %1").arg(roomh->monstr->minattk()));
    ui->Minatkp->setText(QString("MinAttk : %1").arg(roomh->pers->minattk()));
    ui->Maxatkp->setText(QString("MaxAttk : %1").arg(roomh->pers->maxattk()));
}

void RoomBattle::showEvent(QShowEvent *)
{

    if (firstturn == false)
    {
        on_pushButton_clicked();
        renew();
    }



    if (firstturn == true)
    {
        ability->useprebattle(pers,roomh->monstr);
        renew();
        if (roomh->monstr->hpp() <= 0)
        {
        ui->pushButton_2->hide();
        ui->pushButton->setText("Победа");
        win = 1;
        }
        ui->mdmg->setText(QString("Damage : 0"));
        ui->Pdmg->setText(QString("Damage : 0"));
        ui->Roll->setText(QString("Roll : 0"));
        firstturn = false;
    }
}
