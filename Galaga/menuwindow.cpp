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
    ui->setupUi(this);
    //QPixmap prueba(":/miscelanious/assets/press-start-70.png");
    //this->ui->imagePresStart->setPixmap(prueba);


    ThreadPStart* pressChangeImage = new ThreadPStart();

    connect(pressChangeImage,SIGNAL(signalChangeImage(QString)),this,SLOT(changeImageSlot(QString)));

    pressChangeImage->start();

}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::keyPressEvent(QKeyEvent* event)
{
    qDebug() << "entendi el evento";
    const int codigoTecla = event->key();
    if( codigoTecla == Qt::Key_Space)
    {
        qDebug() << "Presione enter";
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

