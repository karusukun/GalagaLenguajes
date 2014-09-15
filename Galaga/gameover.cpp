#include "gameover.h"
#include "ui_gameover.h"
#include "qsizepolicy.h"
#include "QKeyEvent"

gameOver::gameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    ui->setupUi(this);

}

void gameOver::keyPressEvent(QKeyEvent *event)
{
    const int codigoTecla = event->key();
    if( codigoTecla == Qt::Key_Space)
    {
        emit newGame();
        this->hide();
    }
}

gameOver::~gameOver()
{
    delete ui;
}
