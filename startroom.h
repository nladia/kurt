#ifndef STARTROOM_H
#define STARTROOM_H

#include <QMainWindow>
#include "map.h"

namespace Ui {
class StartRoom;
}

class StartRoom : public QMainWindow
{
    Q_OBJECT
    Pers *pers;
    Map *map;

public:
    explicit StartRoom(QWidget *parent = 0, Pers *perss = 0);

    ~StartRoom();

private slots:
    void on_pushButton_5_clicked();

    void renew();

    void showEvent ( QShowEvent * event);

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();


private:
    Ui::StartRoom *ui;
};

#endif // STARTROOM_H
