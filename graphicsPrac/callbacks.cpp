#include "callbacks.h"

int actualY( int y )
{
    return glutGet( GLUT_WINDOW_HEIGHT ) - y;
}

void display() 
{
    utilityCentral( new DisplayEvent() );
}

void keyboard(unsigned char key, int x, int y)
{
    utilityCentral( new KeyboardEvent( key, x, actualY( y ) ) );
}

void reshape( const int w, const int h )
{
    // Switch to projection mode
    glMatrixMode( GL_PROJECTION );
    // Identity matrix means no rotations or translations
    glLoadIdentity();
    // project 3d world space into 2d
    gluOrtho2D( 0.0, w, 0.0, h );
    // point the camera at the 2d projection
    glViewport( 0, 0, w, h );
    // dispatch the reshape event
    utilityCentral( new ReshapeEvent( w, h ) );
}
