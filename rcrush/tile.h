#ifndef TILE_H
#define TILE_H


class Tile
{
   public:
      int x, y;
      const float *color;
      Tile();
      virtual ~Tile();
      Tile(int xLoc, int yLoc, const float col[]);
      virtual void draw() = 0;
};

#endif