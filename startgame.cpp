#include "startgame.h"
#include "ui_startgame.h"

StartGame::StartGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartGame)
{
    ui->setupUi(this);
}

StartGame::~StartGame()
{
    delete ui;
}

void StartGame::on_pushButton_clicked()
{
    pers = new Pers(1);
    StartRoom *h = new StartRoom(this, pers);
    h->show();
    hide();
}

void StartGame::on_pushButton_2_clicked()
{
    pers = new Pers(2);
    StartRoom *h = new StartRoom(this, pers);
    h->show();
    hide();
}

void StartGame::on_pushButton_3_clicked()
{
    pers = new Pers(3);
    StartRoom *h = new StartRoom(this, pers);
    h->show();
    hide();
}
