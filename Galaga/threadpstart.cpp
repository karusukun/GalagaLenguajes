#include "threadpstart.h"

ThreadPStart::ThreadPStart(QObject *parent) :
    QThread(parent)
{
    this->Image = ":/miscelanious/assets/press-start-70.png";

}

void ThreadPStart::run()
{

    bool turn = true;
    while(true)
    {
        this->msleep(600);
        if(turn)
        {
            emit signalChangeImage(Image);
            turn = false;
        }
        else
        {
            emit signalChangeImage("");
            turn = true;
        }
    }
}
