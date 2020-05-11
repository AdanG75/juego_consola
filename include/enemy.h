#ifndef ENEMY_H
#define ENEMY_H

#include "Player.h"

class enemy : public Player
{
    public:
        enemy();
        enemy(int posX, int posY);
        int initialX;
        int initialY;
        void EnemyMove();
        void ResetBegining(bool change);

    protected:

    private:
};

#endif // ENEMY_H
