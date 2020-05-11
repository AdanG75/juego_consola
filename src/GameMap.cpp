#include <iostream>
#include <fstream>
#include <math.h>

#include "GameMap.h"

using namespace std;

GameMap::GameMap()
{
    //ctor
    PlayerCell = NULL;
    EnemyCell = NULL;
    isGameOver = false;
    level = 0;
    change = true;
    LevelAssign();
}

void GameMap::Draw(int dimension)
{
    int row = floor(dimension/1000);
    int columns = dimension - (row*1000);

    for(int i=0; i<row; i++)
    {
        for(int p=0; p<columns; p++)
        {
            cout << cells[i][p].id;
        }
        cout << endl;
    }
}

bool GameMap::SetPlayerCell(int playerX, int playerY)
{
    if(cells[playerX][playerY].IsBlocked() == false)
    {
        if(cells[playerX][playerY].id == '$')
        {
            level++;
            change = true;
        }else if(cells[playerX][playerY].id == 'Q')
        {
            level = 5;
            change = true;
        }
        else
        {
            if(PlayerCell != NULL)
            {
                PlayerCell->id = 0;
            }

            PlayerCell = &cells[playerX][playerY];
            PlayerCell->id = 'H';
        }

        return true;
    }
    return false;
}

int GameMap::LoadMapFromFile(string mapGame)
{
    string line;
    int row = 0;
    int p = 0;
    int col = 0;
    ifstream MyFile(mapGame);

    if(MyFile.is_open())
    {
        while(getline(MyFile, line))
        {
            for(p = 0; p < (static_cast<int>(line.length())); p++)
            {
                if(line[p] == '0')
                {
                    cells[row][p].id = 0;
                }else
                {
                    cells[row][p].id = line[p];
                }
            }
            if(p > col)
                col = p;
            row++;
        }
        MyFile.close();
    }else
    {
        cout << "Fatal error: " << mapGame <<" could not be loaded" << endl;
    }

    return (row*1000)+col;
}

bool GameMap::LevelAssign()
{
    system("cls");
    bool cpChange = change;
    switch (level)
    {
        case 0:
            MapChange("Intro.txt");
            level=1;
            getchar();
            break;
        case 1:
            MapChange("Map.txt");
            break;
        case 2:
            MapChange("Map2.txt");
            break;
        case 3:
            MapChange("Map3.txt");
            break;
        case 4:
            MapChange("Victory.txt");
            isGameOver = true;
            break;
        case 5:
            MapChange("GameOver.txt");
            isGameOver = true;
            break;
        default:
            cout << "Impossible to assign level" << endl;
            break;
    }
    return cpChange;
}

void GameMap::MapChange(string location)
{
    if(change)
    {
        CleanCells();
        row_columns = LoadMapFromFile(location);
        if((level > 0) && (level < 4))
        {
            change = false;
            SetPlayerCell(1, 1);
            //SetEnemyCell(10, 5);
        }

    }
    Draw(row_columns);
}

void GameMap::CleanCells()
{
    for(int i=0; i<25; i++)
    {
        for(int p=0; p<80; p++)
        {
            cells[i][p].id = 0;
        }
    }
}

bool GameMap::SetEnemyCell(int enemyX, int enemyY)
{
    if(cells[enemyX][enemyY].IsBlocked() == false)
    {
            if(EnemyCell != NULL)
            {
                EnemyCell->id = 0;
            }

            EnemyCell = &cells[enemyX][enemyY];
            EnemyCell->id = 'Q';
            return true;
    }
    return false;
}

GameMap::~GameMap()
{
    //dtor
}
