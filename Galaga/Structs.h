#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <QtCore>
#include <QThread>

#define GAME_WIDTH 1280
#define GAME_HEIGHT 900
#define FPS 30

#include <stdlib.h>

typedef struct point
{
    float x;
    float y;

}point;

typedef struct playerShip
{
    point* position = (point*)malloc(sizeof(point));
    char sprites[][2];
    float dx,dy,speed;
    int lives;
    int width,height;
    bool left,down,up,right;

} playerShip;

void updateShip(playerShip* player)
{
    if(player->left)
    {
        player->dx = -1*player->speed;
    }
    if(player->right)
    {
       player->dx = player->speed;
    }
    if(player->up)
    {
        player->dy = -1*player->speed;
    }
    if(player->down)
    {
        player->dy= player->speed;
    }
}

#endif // STRUCTS_H
