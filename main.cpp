#include "startgame.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartGame w;
    w.show();

    return a.exec();
}
