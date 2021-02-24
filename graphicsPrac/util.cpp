#include "util.h"

void utilityCentral(Event *event)
{
   static TelemDisplay telemDisplay;

   event->doAction(telemDisplay);
   glutPostRedisplay();
   delete event;
}

//  Initialize glut callback functions, set the display mode, create a window
void initOpenGL(int argc, char** argv, int width, int height)
{
   glutInit(&argc, argv);

// Choose the display mode for the window.  GLUT_DOUBLE means double buffering
// GLUT_SINGLE is single buffering.  GLUT_RGBA is 24-bit color with 8-bit alpha

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

// Set window size and position
   glutInitWindowSize(width, height);

   glutInitWindowPosition(100, 100);

   glutCreateWindow(argv[0]);

// Subscribed GLUT events

   glutDisplayFunc(display);

   glutKeyboardFunc(keyboard);

   glutReshapeFunc(reshape);

   utilityCentral(new ProgStart());
// This is the color which will be used to clear the display / back plane
// when glClear() is called
   glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

}
