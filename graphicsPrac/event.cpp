#include "event.h"

Event::~Event() {}

void DisplayEvent::doAction( TelemDisplay &telemDisplay )
{
   telemDisplay.displayTasks();
}

ReshapeEvent::ReshapeEvent( int w, int h ) : width( w ), height( h ) {}

void ReshapeEvent::doAction(TelemDisplay &telemDisplay)
{
   glMatrixMode( GL_PROJECTION );      // use an orthographic projection
   glLoadIdentity();                   // initialize transformation matrix
   gluOrtho2D( 0.0, width, 0.0, height );       // set 2D OpenGL coordinates
   glViewport( 0, 0, width, height );  // the same as the screen coordinates
}

KeyboardEvent::KeyboardEvent( unsigned char k, int x, int y ) : key(k), xLoc(x),
   yLoc(y) {}

void KeyboardEvent::doAction( TelemDisplay &telemDisplay )
{
   if (key == ESCAPE_KEY || key == Q_KEY)
   {
      glutLeaveMainLoop();
   }

   if (key == RETURN_KEY)
   {
      telemDisplay.addTask();
      telemDisplay.importTaskData();
   }

   if (key == R_KEY)
   {
      telemDisplay.resetTaskList();
   }
}

void ProgStart::doAction( TelemDisplay &telemDisplay )
{
   glutSetWindowTitle( "FoxProwl - Telemetry" );
}
