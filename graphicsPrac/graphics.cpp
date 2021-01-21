#include "graphics.h"

void DrawTextString(std::string str, int x, int y, const float color[] )
{
    glColor3fv( color );
    glRasterPos2i( x, y );
    for (auto x : str)
	   glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, x );
}
