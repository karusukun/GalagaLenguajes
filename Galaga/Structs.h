#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <QtCore>
#include <QThread>
#include <QLabel>
#include "qpixmap.h"
#include <stdlib.h>
#include "aspectratiopixmaplabel.h"

#define GAME_WIDTH 1280
#define GAME_HEIGHT 600
#define FPS 30

typedef struct point
{
    float x;
    float y;

}point;

typedef struct playerShip
{
    point* position = (point*)malloc(sizeof(point));
    float dx,dy,speed;
    int lives,score;
    int width,height;
    bool left,down,up,right,firing;
    long firingTimer, firingDelay;

    //MERAMENTE PARA USO INTERFAZ
    char* sprites[2];
    AspectRatioPixmapLabel* myLabel;
    bool movement = false;

} playerShip;

void updateShip(playerShip* player);

void drawShip(playerShip* player);

#endif // STRUCTS_H
