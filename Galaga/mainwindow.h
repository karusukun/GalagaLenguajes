#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "gameloopthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //metodos
    playerShip* newPlayerShip();

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent* event);
    bool running;
    GameLoopThread *gameloop;
    playerShip * player;


public slots:
    void gameUpdate();
    void gameDrawn();
    void gameRender();

};

#endif // MAINWINDOW_H
