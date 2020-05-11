#include <cstdlib>

#include "enemy.h"

enemy::enemy()
{
    //ctor
    initialX = 10;
    initialY = 5;
    x = initialX;
    y = initialY;
}

enemy::enemy(int posX, int posY)
{
    //ctor
    initialX = posX;
    initialY = posY;
    x = initialX;
    y = initialY;
    lastX = posX;
    lastY = posY;
}

void enemy::EnemyMove()
{
    lastX = x;
    lastY = y;
    y += ((rand()%3) - 1);
    x += ((rand()%3) - 1);

}

void enemy::ResetBegining(bool change)
{
    x = initialX;
    y = initialY;
    lastX = x;
    lastY = y;
}
