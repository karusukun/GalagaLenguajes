#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QDialog>

namespace Ui {
class gameOver;
}

class gameOver : public QDialog
{
    Q_OBJECT

public:
    explicit gameOver(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent* event);
    ~gameOver();

private:
    Ui::gameOver *ui;
signals:
    void newGame();
};

#endif // GAMEOVER_H
