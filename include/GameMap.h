#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <iostream>
#include "MapCell.h"

class GameMap
{
    public:
        GameMap();
        virtual ~GameMap();

        MapCell * PlayerCell;
        MapCell * EnemyCell;
        MapCell cells[25][85];
        int level;

        bool LevelAssign();
        bool isGameOver;
        int row_columns;
        void Draw(int dimension);
        bool change;
        void MapChange(std::string location);
        bool SetPlayerCell(int playerX, int playerY);
        void CleanCells();
        bool SetEnemyCell(int enemyX, int enemyY);


    protected:
        int LoadMapFromFile(std::string mapGame);

    private:
};

#endif // GAMEMAP_H
