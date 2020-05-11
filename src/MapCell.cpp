#include <iostream>

using namespace std;

#include "MapCell.h"

MapCell::MapCell()
{
    //ctor
    id = 0;
}

bool MapCell::IsBlocked()
{
    if(id == '1')
    {
        return true;
    }else
    {
        return false;
    }
}

MapCell::~MapCell()
{
    //dtor
}
