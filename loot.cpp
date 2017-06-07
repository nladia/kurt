#include "loot.h"
#include "ui_loot.h"

Loot::Loot(QWidget *parent, Pers *persb, int ex, int floorn) :
    QMainWindow(parent),
    ui(new Ui::Loot)
{
    ui->setupUi(this);
    exp = ex;
    floornum = floorn;
    pers = persb;
    par = parent;

    weap = new Weapon(pers->gcls(), pers->levl() + floornum);



    ui->exp->setText(QString("Exp earned : %1").arg(exp));
    ui->min_p->setText(QString("MinAtk : %1").arg(pers->weap->weapmin()));

    ui->max_p->setText(QString("MaxAtk : %1").arg(pers->weap->weapmin() + pers->weap->weapdif()));
    ui->min_m->setText(QString("MinAtk : %1").arg(weap->weapmin()));
    ui->max_m->setText(QString("MinAtk : %1").arg(weap->weapmin() + weap->weapdif()));
}

void Loot::shop()
{

    delete weap;
    ui->exp->hide();

    weap = new Weapon(pers->gcls(), pers->levl() + 15 + floornum);

    ui->min_m->setText(QString("MinAtk : %1").arg(weap->weapmin()));
    ui->max_m->setText(QString("MinAtk : %1").arg(weap->weapmin() + weap->weapdif()));
}

Loot::~Loot()
{
    delete ui;
}

void Loot::on_pushButton_2_clicked()
{
    delete pers->weap;
    pers->weap = weap;
    par->show();
    hide();
}

void Loot::on_pushButton_clicked()
{
    delete weap;
    par->show();
    hide();
}
