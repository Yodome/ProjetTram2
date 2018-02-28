//
// Created by e1701567 on 20/02/2018.
//


#include "../Headers/Position.h"

Position::Position() : d_x{0}, d_y{0}
{}

int Position::getX() const
{
    return 0;
}

int Position::getY() const
{
    return 0;
}

Position& Position::getPos()
{
    return *this;
}

void Position::setPos(int x, int y)
{
    d_x = x;
    d_y =y;
}
