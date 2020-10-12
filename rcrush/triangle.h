#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "gameTile.h"

class Triangle : public GameTile 
{
    public:
        Triangle(int xPos, int yPos, int sideLength, const float col[]);
        ~Triangle();
        void draw();
};

#endif
