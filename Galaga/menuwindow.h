#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "QtCore"
#include "QDebug"
#include "gameover.h"
using namespace std;

namespace Ui {
class MenuWindow;
}

class MenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();
    MainWindow *mw;
    gameOver* go;

public slots:
    void changeImageSlot(QString imagen);
    void newGame();
    void gameEnd();

private:
    Ui::MenuWindow *ui;
    void keyPressEvent(QKeyEvent* event);
};

#endif // MENUWINDOW_H
