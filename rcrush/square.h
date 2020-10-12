#ifndef SQUARE_H
#define SQUARE_H

#include "gameTile.h"

class Square : public GameTile 
{
    public:
        Square(int xPos, int yPos, int size, const float col[]);
        ~Square();
        void draw();
};

#endif
