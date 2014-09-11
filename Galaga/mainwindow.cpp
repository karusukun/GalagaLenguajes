#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QKeyEvent"
#include "Structs.h"
#include <stdlib.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->running = true;
    this->setFocus();
    setFixedSize(GAME_WIDTH,GAME_HEIGHT);

    //inicializacion atributos

    player = newPlayerShip();

    qDebug() << player->lives;


    //Asignación de los Threads
    this->gameloop = new GameLoopThread(true);

    //Connects necesarios para el funcionamiento
    connect(gameloop,SIGNAL(gameUpdate()),this,SLOT(gameUpdate()));
    connect(gameloop,SIGNAL(gameRender()),this,SLOT(gameRender()));
    connect(gameloop,SIGNAL(gameDrawn()),this,SLOT(gameDrawn()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

playerShip *MainWindow::newPlayerShip()
{
    playerShip* temp = (playerShip*)malloc(sizeof(playerShip));
    temp->position->x = GAME_WIDTH /2;
    temp->position->y = GAME_HEIGHT - (GAME_HEIGHT - 100);
    temp->dx = temp->dy = 0;
    temp->lives = 3;
    temp->speed = 5;
    temp->up = temp->down = temp->left = temp->right = false;
    temp->width = 50;
    temp->height = 50;
    return temp;
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    const int codigoTecla = event->key();
    if( codigoTecla == Qt::Key_Enter)
    {

    }

}

void MainWindow::gameUpdate()
{

}

void MainWindow::gameDrawn()
{


}
void MainWindow::gameRender()
{


}
