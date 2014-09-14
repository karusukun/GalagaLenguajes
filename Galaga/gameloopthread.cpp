#include "gameloopthread.h"

GameLoopThread::GameLoopThread(QObject *parent) :
    QThread(parent)
{
}

GameLoopThread::GameLoopThread(bool running)
{
    this->running = running;
    totalTime = 0;
}

void GameLoopThread::run()
{
    QElapsedTimer timer;
    timer.start();
    long targetTime = 1000/fps;

    while(running)
    {
        timer.restart();
        emit gameUpdate();
        emit gameRender();
        emit gameDrawn();

        URDTimeMilis = timer.nsecsElapsed()/1000000;
        waitTime = targetTime - URDTimeMilis;

        this->msleep(waitTime);

        this->totalTime += timer.nsecsElapsed();
        frameCount++;

        if(frameCount == maxFrameCount)
        {
            averageFPS = 1000.0/((totalTime/frameCount)/ 1000000);
            frameCount = 0;
            totalTime = 0;

        }
    }
}
