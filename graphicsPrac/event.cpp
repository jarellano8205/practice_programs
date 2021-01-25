#include "event.h"

Event::~Event() {}

/***************************************************************************//**
 * @brief Constructor
 *
 * Display event is called under a number of circumstances.  During its action
 * method, we just swap the buffers (we are assuming double buffer mode)
 * If there is a repaint required by the game, here is where that would likely
 * happen
 ******************************************************************************/
void DisplayEvent::doAction(TelemDisplay &telemDisplay)
{
   telemDisplay.displayTasks();
}

/***************************************************************************//**
 * @brief Constructor
 *
 * This event gets called continuously as the window is resized.  This event
 * usually also triggers a display event
 *
 * @param[in] w - width (in pixels) of the window
 * @param[in] h - height (in pixels) of the window
 ******************************************************************************/
ReshapeEvent::ReshapeEvent(int w, int h) : width(w), height(h) {}

void ReshapeEvent::doAction(TelemDisplay &telemDisplay)
{
   glMatrixMode( GL_PROJECTION );      // use an orthographic projection
   glLoadIdentity();                   // initialize transformation matrix
   gluOrtho2D( 0.0, width, 0.0, height );       // make OpenGL coordinates
   glViewport( 0, 0, width, height );  // the same as the screen coordinates
}

/***************************************************************************//**
 * @brief Constructor
 *
 * A keyboard key has been pressed.  This object's action method will react
 * to the escape key by leaving the main glut event loop.  If you need to do
 * resource freeing, doing so before leaving the glut main loop (or immediately
 * thereafter) is suggested
 *
 * @param[in] k - the ascii value of the key that was pressed
 * @param[in] x - the x-coordinate of where the key 'k' was pressed
 * @param[in] y - the y-coordinate of where the key 'k' was pressed
 ******************************************************************************/
KeyboardEvent::KeyboardEvent(unsigned char k, int x, int y) : key(k), xLoc(x), yLoc(y) {}

void KeyboardEvent::doAction(TelemDisplay &telemDisplay)
{
   if (key == ESCAPE_KEY)
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

void ProgStart::doAction(TelemDisplay &telemDisplay)
{
   glutSetWindowTitle("FoxProwl - Telemetry");
   glutPostRedisplay();
}
