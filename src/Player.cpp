#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
    //ctor
    x = 1;
    y = 1;
}

void Player::callInput(int levelPlayer, bool change)
{
    ResetBegining(change);
    char userInput = ' ';
    cin >> userInput;

    lastX = x;
    lastY = y;
    if((levelPlayer > 0) && (levelPlayer < 4))
    {
       switch(userInput)
        {
            case 'w':
                x--;
                break;
            case 'a':
                y--;
                break;
            case 's':
                x++;
                break;
            case 'd':
                y++;
                break;
            default:
                break;
        }
    }
}

void Player::ResetToSafePosition()
{
    x = lastX;
    y = lastY;
}

void Player::ResetBegining(bool change)
{
    if(change)
    {
        //cout << "Hola"<< endl;
        x = 1;
        y = 1;
        lastX = 1;
        lastY = 1;
        //system("pause");
    }
}

Player::~Player()
{
    //dtor
}
