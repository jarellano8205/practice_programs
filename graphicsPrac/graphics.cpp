#include "graphics.h"

void DrawFilledRectangle (float x1, float y1, float x2, float y2,
   const float color[] )
{
   glColor3fv( color );
   glBegin( GL_POLYGON );
   glVertex2f( x1, y1 );
   glVertex2f( x2, y1 );
   glVertex2f( x2, y2 );
   glVertex2f( x1, y2 );
   glEnd();
   glFlush();
}

void DrawTextString( std::string string, int x, int y, const float color[] )
{
   glColor3fv( color );
   glRasterPos2i( x, y );
   for ( auto character : string )
   {
	   glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, character );
   }
}
