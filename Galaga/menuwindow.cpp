#include "menuwindow.h"
#include "ui_menuwindow.h"
#include "threadpstart.h"
#include "QKeyEvent"

using namespace std;

MenuWindow::MenuWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuWindow)
{
    mw = new MainWindow();
    go = new gameOver();
    ui->setupUi(this);

    ThreadPStart* pressChangeImage = new ThreadPStart();

    connect(pressChangeImage,SIGNAL(signalChangeImage(QString)),this,SLOT(changeImageSlot(QString)));
    connect(go,SIGNAL(newGame()),this,SLOT(newGame()));
    connect(mw,SIGNAL(gameEnd()),this,SLOT(gameEnd()));
    pressChangeImage->start();

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::keyPressEvent(QKeyEvent* event)
{
    const int codigoTecla = event->key();
    if( codigoTecla == Qt::Key_Space)
    {
        this->mw->show();
        this->hide();
    }

}



void MenuWindow::changeImageSlot(QString imagen)
{
    QPixmap t_pixmap(imagen);
    this->ui->imagePresStart->setPixmap(t_pixmap);
    this->ui->imagePresStart->update();
}

void MenuWindow::newGame()
{
    delete this->mw;
    this->mw = new MainWindow();
    connect(mw,SIGNAL(gameEnd()),this,SLOT(gameEnd()));
    this->show();
    this->go->hide();
}

void MenuWindow::gameEnd()
{
    mw->hide();
    go->show();
}

