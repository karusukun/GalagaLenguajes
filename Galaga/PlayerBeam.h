#ifndef PLAYERBEAM_H
#define PLAYERBEAM_H
#include "Structs.h"
#include "math.h"
#include "QLabel"
#include "QDebug"
typedef struct PlayerBeam
{
    point* position = (point*)malloc(sizeof(point));

    double dx,dy;
    double speed;
    double radians;
    int heigh;
    int width;
    int imgPos;

    // MERAMENTE PARA LOGICA
    char* sprites[11];
    QLabel* myLabel;

}PlayerBeam;

bool UpdatePlayerBeam(PlayerBeam* beam);
PlayerBeam* newPlayerBeam(double angle, int x, int y, QLabel* label);
void DrawPlayerBeam(PlayerBeam* beam);


#endif // PLAYERBEAM_H
