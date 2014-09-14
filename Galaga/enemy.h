#ifndef ENEMY_H
#define ENEMY_H

#include <QString>
#include <QList>
#include <QLabel>

typedef enum {NORMAL, DISPARADOR, REGRESADOR, REGDIS, BOSS} enemyType_T;

typedef struct enemy
{
    int id;
    enemyType_T type;
    int life;
    float posX;
    float posY;
    bool moves;
    bool shoots;
    int posImg, posImgMx;
    float speed;
    double angle;
    int width;
    int height;
    int imageNumber;
    const char* imageName[3];// uso unicamente para manejo de interfaz
    QLabel* image;
    float dx;
    float dy;
    double radians;

    bool ready,dead;

}enemy_T;


enemy_T* newEnemy(enemyType_T tipo, int nid, QLabel* nimage,int x, int y);
void hit(enemy_T * enemy);
void enemyUpdate(enemy_T* enemy);
void enemyDraw(enemy_T* enemy);
int checkEnemyValue(enemyType_T type);

#endif // ENEMY_H
