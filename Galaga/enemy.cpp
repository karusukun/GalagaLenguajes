#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>
#include "math.h"
#include <QList>
#include <QString>

enemy_T* newEnemy(enemyType_T tipo, int nid, QLabel* nimage,int x, int y)
{


    enemy_T* nEnemy = (enemy_T*) malloc(sizeof(enemy_T));

    nEnemy->ready = nEnemy->dead = false;
    nEnemy->posImg = 0;
    nEnemy->angle = rand() * 140 + 20;
    nEnemy->radians = nEnemy->angle* M_PI /180;



    switch (tipo) {
    case NORMAL:
    {
        nEnemy->id = nid;
        nEnemy->life = 1;
        nEnemy->moves = true;
        nEnemy->shoots = false;
        nEnemy->type = tipo;
        nEnemy->posX = x;
        nEnemy->posY = y;
        nEnemy->speed =6;
        nEnemy->width = 50;
        nEnemy->height = 50;

        nEnemy->imageName[0] = ":/gameElement/assets/enemy1-1.png";
        nEnemy->imageName[1] = ":/gameElement/assets/enemy1-2.png";
        nEnemy->imageName[2] = ":/gameElement/assets/enemy1-3.png";
        nEnemy->imageNumber = 3;
        nEnemy->image = nimage;
        break;
    }
    case DISPARADOR:
    {
        nEnemy->id = nid;
        nEnemy->life = 1;
        nEnemy->moves = false;
        nEnemy->shoots = true;
        nEnemy->type = tipo;
        nEnemy->posX = x;
        nEnemy->posY = y;
        nEnemy->speed = 5;
        nEnemy->width = 50;
        nEnemy->height = 50;

        nEnemy->imageName[0] = ":/gameElement/assets/enemy2-1.png";
        nEnemy->imageName[1] = ":/gameElement/assets/enemy2-2.png";
        nEnemy->imageNumber = 2;
        nEnemy->image = nimage;
        break;
    }
    case REGRESADOR:
    {
        nEnemy->id = nid;
        nEnemy->life = 1;
        nEnemy->moves = true;
        nEnemy->shoots = false;
        nEnemy->type = tipo;
        nEnemy->posX = x;
        nEnemy->posY = y;
        nEnemy->speed = 7;
        nEnemy->width = 50;
        nEnemy->height = 50;

        nEnemy->imageName[0] = ":/gameElement/assets/enemy3-1.png";
        nEnemy->imageName[1] = ":/gameElement/assets/enemy3-2.png";
        nEnemy->imageNumber = 2;
        nEnemy->image = nimage;
        break;
    }
    case REGDIS:
    {
        nEnemy->id = nid;
        nEnemy->life = 1;
        nEnemy->moves = true;
        nEnemy->shoots = true;
        nEnemy->type = tipo;
        nEnemy->posX = x;
        nEnemy->posY = y;
        nEnemy->speed = 6;
        nEnemy->width = 50;
        nEnemy->height = 50;

        nEnemy->imageName[0] = ":/gameElement/assets/enemy4-1.png";
        nEnemy->imageName[1] = ":/gameElement/assets/enemy4-1.png";
        nEnemy->imageNumber = 2;
        nEnemy->image = nimage;
        break;
    }
    case BOSS:
    {
        nEnemy->id = nid;
        nEnemy->life = 2;
        nEnemy->moves = false;
        nEnemy->shoots = false;
        nEnemy->type = tipo;
        nEnemy->posX = x;
        nEnemy->posY = y;
        nEnemy->speed = 4;
        nEnemy->width = 80;
        nEnemy->height = 80;

        nEnemy->imageName[0] = ":/gameElement/assets/boss1.png";
        nEnemy->imageName[1] = ":/gameElement/assets/boss2.png";
        nEnemy->imageNumber = 2;
        nEnemy->image = nimage;
        break;
    }
    }


    nEnemy->dx = cos(nEnemy->radians) * nEnemy->speed;
    nEnemy->dy = sin(nEnemy->radians) * nEnemy->speed;

    QPixmap newPix(nEnemy->imageName[0]);

    nEnemy->image->setScaledContents(true);
    nEnemy->image->setPixmap(newPix);
    nEnemy->image->setFixedSize(nEnemy->width,nEnemy->height);
    nEnemy->image->move(nEnemy->posX,nEnemy->posY);

    return nEnemy;
}

void hit(enemy_T * enemy)
{
    enemy->life--;
    if(enemy->life <= 0)
    {
        enemy->dead = true;
    }

}

void enemyUpdate(enemy_T* enemy)
{

}

void enemyDraw(enemy_T* enemy)
{
    //enemy->posImg++;
    if(enemy->posImg >= enemy->imageNumber -1)
        enemy->posImg = 0;

    QPixmap newPix(enemy->imageName[enemy->posImg]);

    enemy->image->setPixmap(newPix);
    enemy->image->move(enemy->posX,enemy->posY);
}


//NORMAL, DISPARADOR, REGRESADOR, REGDIS, BOSS

int checkEnemyValue(enemyType_T type)
{
    switch(type)
    {
        case NORMAL:
        return 100;
        break;

        case DISPARADOR:
        return 200;
        break;

        case REGRESADOR:
        return 300;
        break;

        case REGDIS:
        return 500;
        break;

        case BOSS:
        return 100;
        break;
    }
}




