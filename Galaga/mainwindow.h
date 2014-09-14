#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindow.h"
#include "DataLibrary.h"
#include "qlist.h"

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
    playerShip* newPlayerShip(AspectRatioPixmapLabel* label);

private:
    Ui::MainWindow *ui;
    bool running;
    GameLoopThread *gameloop;
    playerShip * player;
    int level = 1;
    QList<PlayerBeam*>* playerBullets;
    QList<enemy_T*>* enemies;
    char* numbers[10];
    QList<QLabel*>* scoreNumbers;
    QList<QLabel*>* Lives;
    bool enemyKilled = false;
    bool playerHitted = true;
    enemy_T* enemigos[][10];


    void keyPressEvent(QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);
    void refreshScore();
    void clearScore();
    void refreshLives();
    void clearLives();
    void generateNextLevel();

public slots:
    void gameUpdate();
    void gameDrawn();
    void gameRender();

};

#endif // MAINWINDOW_H
