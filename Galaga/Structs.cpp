#include "Structs.h"

void updateShip(playerShip* player)
{
    QElapsedTimer timer;

    if(player->left)
    {
        player->dx = (-1)*player->speed;
        player->movement = true;
    }
    if(player->right)
    {
       player->dx = player->speed;
       player->movement = true;
    }
    if(player->up)
    {
        player->dy = (-1)*player->speed;
        player->movement = true;
    }
    if(player->down)
    {
        player->dy= player->speed;
        player->movement = true;
    }

    player->position->x += player->dx;
    player->position->y += player->dy;

    if(player->position->x < 0)
        player->position->x = 0;
    if(player->position->y < 0)
        player->position->y = 0;
    if(player->position->x > (GAME_WIDTH- (player->width)))
        player->position->x = (GAME_WIDTH - (player->width));
    if(player->position->y > (GAME_HEIGHT - (player->height)))
        player->position->y = GAME_HEIGHT - (player->height);

    player->dx = 0;
    player->dy = 0;


}

void drawShip(playerShip* player)
{
    QPixmap* nuevoPix;
    if(player->movement)
    {
        player->movement = false;
        nuevoPix = new QPixmap(player->sprites[1]);
    }
    else
        nuevoPix = new QPixmap(player->sprites[0]);

    player->myLabel->setPixmap(*nuevoPix);
    player->myLabel->setFixedSize(50,50);
    player->myLabel->update();
    player->myLabel->move(player->position->x,player->position->y);

}
