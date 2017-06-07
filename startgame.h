#ifndef STARTGAME_H
#define STARTGAME_H

#include <QMainWindow>
#include "Pers.h"
#include "startroom.h"

namespace Ui {
class StartGame;
}

class StartGame : public QMainWindow
{
    Q_OBJECT
    Pers *pers;

public:
    explicit StartGame(QWidget *parent = 0);
    ~StartGame();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::StartGame *ui;
};

#endif // STARTGAME_H
