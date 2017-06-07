#include "ability.h"
#include "ui_ability.h"

Ability::Ability(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ability)
{
    ui->setupUi(this);

    pass[0] = false;
    pass[1] = false;
    pass[2] = false;
    pass[3] = false;
    pass[4] = false;

    prebattlescr = parent;

    prebat[0][0] = false;
    prebat[1][0] = false;
    prebat[2][0] = false;
    prebat[3][0] = false;
    prebat[4][0] = false;

    prebat[0][1] = false;
    prebat[1][1] = false;
    prebat[2][1] = false;
    prebat[3][1] = false;
    prebat[4][1] = false;

    prebatcd[0][0] = 4;
    prebatcd[1][0] = 2;
    prebatcd[2][0] = 2;
    prebatcd[3][0] = 6;
    prebatcd[4][0] = 16;

    scrtype = 0;

    inbat[0] = false;
    inbat[1] = false;
    inbat[2] = false;
    inbat[3] = false;
    inbat[4] = false;

    inbatcd[0][0] = 3;
    inbatcd[1][0] = 6;
    inbatcd[2][0] = 4;
    inbatcd[3][0] = 4;
    inbatcd[4][0] = 0;

    inbatcd[0][1] = 1;
    inbatcd[1][1] = 3;
    inbatcd[2][1] = 3;
    inbatcd[3][1] = 1;
    inbatcd[4][1] = 1;

    for (int i = 0; i < 5; i++)
    {
        inbatcd[i][2] = 0;
        inbatcd[i][3] = 0;
        prebatcd[i][1] = 0;
    }

    bindbuttons();

    abilitynamebind();

    renew();
    afterbattle = 0;
}

Ability::~Ability()
{
    delete ui;

}

void Ability::abilitynamebind()
{
    abilityname[1] = "уклонение";
    abilityname[2] = "отдача";
    abilityname[3] = "обучение";
    abilityname[4] = "мини кд";
    abilityname[5] = "Продление";
    abilityname[6] = "Хил";
    abilityname[7] = "Омоложение";
    abilityname[8] = "Зачаровать оружие";
    abilityname[9] = "Петля времени";
    abilityname[10] = "ВанШот";
    abilityname[11] = "Божественный шит";
    abilityname[12] = "Вамперизм";
    abilityname[13] = "Проклятие разложения";
    abilityname[14] = "Удар Провосудия";
    abilityname[15] = "Огненное оружие";

}

void Ability::abilitybuy(int x, int y)
{
    if (x == 0)
        crepasive(y);
    if (x == 1)
        creprebattle(y);
    if (x == 2)
        creinbattle(y);
}

void Ability::crepasive(int pas)
{
    pass[pas] = true;
    button[pas + 1]->setText(abilityname[pas + 1] + "\n Get");
    if (pas == 3)
    {
        prebatcd[0][0] = 3;
        prebatcd[1][0] = 1;
        prebatcd[2][0] = 1;
        prebatcd[3][0] = 5;
        prebatcd[4][0] = 15;

        inbatcd[0][0] = 2;
        inbatcd[1][0] = 5;
        inbatcd[2][0] = 3;
        inbatcd[3][0] = 3;
        inbatcd[4][0] = 0;
    }
    if (pas == 4)
    {
        inbatcd[0][1] = 2;
        inbatcd[1][1] = 4;
        inbatcd[2][1] = 4;
        inbatcd[3][1] = 2;
        inbatcd[4][1] = 1;
    }
}

void Ability::creprebattle(int pre)
{
    prebat[pre][0] = true;
}

void Ability::creinbattle(int inb)
{
    inbat[inb] = true;
}

void Ability::usepassive(Monster *monster, int* mdmg)
{
    if (pass[0] == true)
        if (rand() % 10 == 1)
            *mdmg = 0;

    if (pass[1] == true)
    {
        monster->dmg(*mdmg / 8);
    }
}

void Ability::useinbattle(Pers *pers, Monster *monster, int* pdmg, int* mdmg)
{
    if ((inbat[0] == true) && (inbatcd[0][3]>0) && (*mdmg > 0))                  //тут
    {
        inbatcd[0][3]--;
        *mdmg = 0;
    }
    if ((inbat[1] == true) && (inbatcd[1][3]>0))
    {
        inbatcd[1][3]--;
        pers->dmg(-1 * (*pdmg / 3));
    }
    if ((inbat[2] == true) && (inbatcd[2][3]>0))
    {
        inbatcd[2][3]--;
        monster->dmg(30);
    }
    if ((inbat[3] == true) && (inbatcd[3][3]>0))
    {
        inbatcd[3][3]--;
        monster->dmg(150);
    }
    if ((inbat[4] == true) && (inbatcd[4][3]>0))                                //tyt
    {
        *pdmg += 10;
        inbatcd[4][3]--;
    }
}

void Ability::useprebattle(Pers *pers, Monster *monster)
{
    if (prebat[0][0] == true && prebat[0][1] == true)
    {
        pers->heal(5);
        prebatcd[0][1] = prebatcd[0][0];
    }

    if (prebat[1][0] == true && prebat[1][1] == true)       //левачок
    {
        prebatcd[1][1] = prebatcd[1][0];
    }

    if (prebat[2][0] == true && prebat[2][1] == true)
    {
        afterbattle = pers->attack() / 5;
        pers->incdmg(afterbattle);
        prebatcd[2][1] = prebatcd[2][0];
    }

    if (prebat[3][0] == true && prebat[3][1] == true)
    {
        afterbattle = pers->hpp();
        prebatcd[3][1] = prebatcd[3][0];
    }

    if (prebat[4][0] == true && prebat[4][1] == true)
    {
        monster->dmg(monster->hpp());
        prebatcd[4][1] = prebatcd[4][0];
    }
}

void Ability::useafterbattle(Pers *pers)
{
    if (prebat[0][0] == true && prebat[0][1] == true)
    {
        prebat[0][1] = false;
    }

    if (prebat[1][0] == true && prebat[0][1] == true)           //левачок
    {
        prebat[1][1] = false;
    }

    if (prebat[2][0] == true && prebat[2][1] == true)
    {
        pers->incdmg(-1 * afterbattle);
        afterbattle = 0;
        prebat[2][1] = false;
    }

    if (prebat[3][0] == true && prebat[3][1] == true)
    {
        pers->sethp(afterbattle);
        afterbattle = 0;
        prebat[3][1] = false;
    }

    if (prebat[4][0] == true && prebat[4][1] == true)
    {
        prebat[4][1] = false;
    }

    inbatcd[0][3] = 0;
    inbatcd[1][3] = 0;
    inbatcd[2][3] = 0;
    inbatcd[3][3] = 0;
    inbatcd[4][3] = 0;

    inbatcd[0][2] = 0;
    inbatcd[1][2] = 0;
    inbatcd[2][2] = 0;
    inbatcd[3][2] = 0;
    inbatcd[4][2] = 0;

    cdprebattle();
}

void Ability::cdprebattle()
{
    for (int i = 0; i < 5; i++)
        if (prebatcd[i][1] > 0) prebatcd[i][1]--;
}

void Ability::cdinbattle()
{
    for (int i = 0; i < 5; i++)
        if (inbatcd[i][2] > 0) inbatcd[i][2]--;
}

void Ability::useability(int x, int y)
{
    if (x == 1)
    {
        prebat[y][1] = true;
    }
    if (x == 2)
    {
        inbatcd[y][2] = inbatcd[y][0];
        inbatcd[y][3] = inbatcd[y][1];
    }

}

bool Ability::abilityavailable(int x, int y)
{
    bool k = false;
    if (x == 0)
        if (pass[y] == true) k = true;

    if (x == 1)
    {
        if ((prebatcd[y][1] == 0) && (prebat[y][0] == true)) k = true;

    }
    if (x == 2)
    {
        if ((inbatcd[y][2] == 0) && inbat[y] == true) k = true;
    }
    return k;
}

void Ability::renew()
{
    for(int i = 1; i<3; i++)
        for(int j = 0; j < 5; j++)
            if(abilityavailable(i,j))
            {
                button[j+1 + i*5]->setText(abilityname[j+1 + i*5] + "\n Ready");
                button[j+1 + i*5]->setDisabled(false);
            }
            else
            {
                if (i == 1)
                {
                    if(prebatcd[j][1] == 0)
                    {
                        button[j+1 + i*5]->setText(abilityname[j+1 + i*5] + "\n No skill");
                    }
                    if (prebatcd[j][1] > 0)
                        button[j+1 + i*5]->setText(abilityname[j+1 + i*5] + QString("\n CD = %1").arg(prebatcd[j][1]));
                }
                if (i == 2)
                {
                    if(inbatcd[j][2] == 0)
                    {
                        button[j+1 + i*5]->setText(abilityname[j+1 + i*5] + "\n No skill");
                    }
                    if (inbatcd[j][2] > 0)
                        button[j+1 + i*5]->setText(abilityname[j+1 + i*5] + QString("\n CD = %1").arg(inbatcd[j][2]));
                }

                button[j+1 + i*5]->setDisabled(true);
            }

    if (scrtype == 0)
    {
        disableinbattle();
        disableprebattle();
    }
    if (scrtype == 1)
        disableinbattle();
    if (scrtype == 2)
        disableprebattle();

}

void Ability::bindbuttons()
{
    button[1] = ui->b1;
    button[2] = ui->b2;
    button[3] = ui->b3;
    button[4] = ui->b4;
    button[5] = ui->b5;
    button[6] = ui->b6;
    button[7] = ui->b7;
    button[8] = ui->b8;
    button[9] = ui->b9;
    button[10] = ui->b10;
    button[11] = ui->b11;
    button[12] = ui->b12;
    button[13] = ui->b13;
    button[14] = ui->b14;
    button[15] = ui->b15;
}

void Ability::showEvent(QShowEvent *)
{
    renew();
}

void Ability::battle(Pers *pers, Monster *monster, int* pdmg, int* mdmg)
{
    usepassive(monster, mdmg);

    useinbattle(pers, monster, pdmg, mdmg);

    cdinbattle();
}

void Ability::remap(QWidget *parent, int x)
{
    prebattlescr = parent;

    scrtype = x;

    if (x == 0)
    {
        ui->pushButton->setText("Назад");
    }
    if (x == 1)
    {
        ui->pushButton->setText("В бой!");
    }
    if (x == 2)
    {
        ui->pushButton->setText("Обычная атака");
    }

}

void Ability::on_pushButton_clicked()
{
    prebattlescr->show();
    hide();
}

void Ability::disableinbattle()
{
    button[11]->setDisabled(true);
    button[12]->setDisabled(true);
    button[13]->setDisabled(true);
    button[14]->setDisabled(true);
    button[15]->setDisabled(true);
}

void Ability::disableprebattle()
{
    button[6]->setDisabled(true);
    button[7]->setDisabled(true);
    button[8]->setDisabled(true);
    button[9]->setDisabled(true);
    button[10]->setDisabled(true);
}

void Ability::skillsenabled()
{
    button[6]->setDisabled(false);
    button[7]->setDisabled(false);
    button[8]->setDisabled(false);
    button[9]->setDisabled(false);
    button[10]->setDisabled(false);

    button[11]->setDisabled(false);
    button[12]->setDisabled(false);
    button[13]->setDisabled(false);
    button[14]->setDisabled(false);
    button[15]->setDisabled(false);
}

void Ability::on_b11_clicked()
{
    useability(2,0);
    on_pushButton_clicked();
}

void Ability::on_b12_clicked()
{
    useability(2,1);
    on_pushButton_clicked();
}

void Ability::on_b13_clicked()
{
    useability(2,2);
    on_pushButton_clicked();
}

void Ability::on_b14_clicked()
{
    useability(2,3);
    on_pushButton_clicked();
}

void Ability::on_b15_clicked()
{
    useability(2,4);
    on_pushButton_clicked();
}

void Ability::on_b6_clicked()
{
    prebat[0][1] = true;
    on_pushButton_clicked();
}

void Ability::on_b7_clicked()       //левачок
{
    prebat[1][1] = true;
    on_pushButton_clicked();
}

void Ability::on_b8_clicked()
{
    prebat[2][1] = true;
    on_pushButton_clicked();
}

void Ability::on_b9_clicked()
{
    prebat[3][1] = true;
    on_pushButton_clicked();
}

void Ability::on_b10_clicked()
{
    prebat[4][1] = true;
    on_pushButton_clicked();
}
