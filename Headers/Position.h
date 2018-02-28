//
// Created by e1701567 on 20/02/2018.
//

#ifndef PROJETTRAM_POSITION_H
#define PROJETTRAM_POSITION_H


class Position
{
public:
    Position();
    int getX() const;
    int getY() const;
    Position& getPos()  ;
    void setPos(int x, int y)  ;


private:
    int d_x;
    int d_y;
};


#endif //PROJETTRAM_POSITION_H