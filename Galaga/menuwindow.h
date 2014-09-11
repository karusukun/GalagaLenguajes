#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QDialog>
#include "mainwindow.h"
#include "QtCore"
#include "QDebug"

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

public slots:
    void changeImageSlot(QString imagen);

private:
    Ui::MenuWindow *ui;
    void keyPressEvent(QKeyEvent* event);
};

#endif // MENUWINDOW_H
