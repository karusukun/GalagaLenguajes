#ifndef USERINPUTHANDLER_H
#define USERINPUTHANDLER_H

#include <QThread>

class userInputHandler : public QThread
{
    Q_OBJECT
public:
    explicit userInputHandler(QObject *parent = 0);

signals:

public slots:

};

#endif // USERINPUTHANDLER_H
