#include "PlayerBeam.h"
#include "QPixmap"
#include "qdebug.h"

PlayerBeam* newPlayerBeam(double angle, int x, int y, QLabel* label)
{
    PlayerBeam* tmp = (PlayerBeam*)malloc(sizeof(PlayerBeam));
    tmp->position = (point*)malloc(sizeof(point));
    tmp->position->x = x;
    tmp->position->y = y;
    tmp->radians = (angle * M_PI)/180;
    tmp->dx = cos(tmp->radians);
    tmp->dy = sin(tmp->radians);
    tmp->speed = 20;
    tmp->width = 8;
    tmp->heigh = 15;

    tmp->imgPos = 0;
    tmp->sprites[0] = ":/gameElement/assets/laserBlue01.png";
    tmp->sprites[1] = ":/gameElement/assets/laserBlue02.png";
    tmp->sprites[2] = ":/gameElement/assets/laserBlue03.png";
    tmp->sprites[3] = ":/gameElement/assets/laserBlue04.png";
    tmp->sprites[4] = ":/gameElement/assets/laserBlue05.png";
    tmp->sprites[5] = ":/gameElement/assets/laserBlue06.png";
    tmp->sprites[6] = ":/gameElement/assets/laserBlue07.png";
    tmp->sprites[7] = ":/gameElement/assets/laserBlue08.png";
    tmp->sprites[8] = ":/gameElement/assets/laserBlue09.png";
    tmp->sprites[9] = ":/gameElement/assets/laserBlue10.png";
    tmp->sprites[10] = ":/gameElement/assets/laserBlue11.png";

    tmp->myLabel = label;

    QPixmap newPixmap(tmp->sprites[0]);
    tmp->myLabel->setPixmap(newPixmap);
    tmp->myLabel->setScaledContents(true);
    tmp->myLabel->setFixedSize(tmp->width,tmp->heigh);
    tmp->myLabel->move(tmp->position->x, tmp->position->y);
    return tmp;
}

bool UpdatePlayerBeam(PlayerBeam* beam)
{
    beam->position->x += beam->dx * beam->speed;
    beam->position->y += beam->dy * beam->speed;

    if((beam->position->x < 0) || (beam->position->x > (GAME_WIDTH - beam->width))
            || (beam->position->y < 0) || (beam->position->y > (GAME_HEIGHT - beam->heigh)))
        return true;



    return false;

}

void DrawPlayerBeam(PlayerBeam* beam)
{
    beam->imgPos++;
    if(beam->imgPos >= 11)
        beam->imgPos = 0;

    QPixmap* nuevoPix = new QPixmap(beam->sprites[beam->imgPos]);
    beam->myLabel->setPixmap(*nuevoPix);
    beam->myLabel->setFixedSize(beam->width, beam->heigh);
    beam->myLabel->update();
    beam->myLabel->move(beam->position->x,beam->position->y);

}
