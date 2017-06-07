#include "looser.h"
#include "ui_looser.h"

Looser::Looser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Looser)
{
    ui->setupUi(this);
}

Looser::~Looser()
{
    delete ui;
}
