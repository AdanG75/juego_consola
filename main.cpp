#include <iostream>

#include "Player.h"
#include "MapCell.h"
#include "GameMap.h"
#include "enemy.h"

using namespace std;

int main()
{
    Player Hero;
    GameMap Map;
    bool changeG;
    enemy evil1(10,5);
    enemy evil2(5,4);
    enemy evil3(10,1);

    while(!Map.isGameOver)
    {
        evil1.EnemyMove();
        if(!Map.SetEnemyCell(evil1.x, evil1.y))
        {
            evil1.ResetToSafePosition();
        }
        if(Map.level == 2)
        {
            evil2.EnemyMove();
            if(!Map.SetEnemyCell(evil2.x, evil2.y))
            {
                evil2.ResetToSafePosition();
            }
        }
        if(Map.level == 3)
        {
            evil3.EnemyMove();
            if(!Map.SetEnemyCell(evil3.x, evil3.y))
            {
                evil3.ResetToSafePosition();
            }
        }
        if(!Map.SetPlayerCell(Hero.x, Hero.y))
        {
            Hero.ResetToSafePosition();
        }
        changeG = Map.LevelAssign();
        Hero.callInput(Map.level, changeG);
        evil1.ResetBegining(changeG);
        evil2.ResetBegining(changeG);
        evil3.ResetBegining(changeG);
    }


    return 0;
}
