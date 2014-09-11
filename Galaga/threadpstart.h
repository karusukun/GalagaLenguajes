#ifndef THREADPSTART_H
#define THREADPSTART_H

#include <QThread>
#include <stdio.h>
#include <QtCore>
#include <qdebug.h>

using namespace std;

class ThreadPStart : public QThread
{
    Q_OBJECT
public:

    QString Image;

    explicit ThreadPStart(QObject *parent = 0);
    void run();

signals:
    void signalChangeImage(QString);

public slots:

};

#endif // THREADPSTART_H
