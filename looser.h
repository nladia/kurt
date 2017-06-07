#ifndef LOOSER_H
#define LOOSER_H

#include <QMainWindow>

namespace Ui {
class Looser;
}

class Looser : public QMainWindow
{
    Q_OBJECT

public:
    explicit Looser(QWidget *parent = 0);
    ~Looser();

private:
    Ui::Looser *ui;
};

#endif // LOOSER_H
