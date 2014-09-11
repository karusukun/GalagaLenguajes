#ifndef GAMELOOPTHREAD_H
#define GAMELOOPTHREAD_H

#include <QThread>
#include "Structs.h"

class GameLoopThread : public QThread
{
    Q_OBJECT
public:


    explicit GameLoopThread(QObject *parent = 0);
    GameLoopThread(bool running);
    void run();
private:

    int fps = FPS;
    double averageFPS;

    bool running;
    long startTime, URDTimeMilis, waitTime,totalTime;

    int frameCount = 0;
    int maxFrameCount = 30;

signals:
    void gameUpdate();
    void gameRender();
    void gameDrawn();

public slots:

};

#endif // GAMELOOPTHREAD_H
