#include "util.h"

/***************************************************************************//**
 * @brief utilityCentral handles event objects
 *
 * Any events such as mouse clicks, key presses, etc. call a specific doAction
 * function that executes an action related to the event.
 *
 * glutPostRedisplay is a call for the freeglut graphics to call a display
 * event and redraw the board after each event.
 *
 * After using the event object information it is deleted to free the memory.
 *
 * @param[in] event - Pointer to an event object, each doAction function acts
 * 		      differently based on the type of event.
 ******************************************************************************/
void utilityCentral(Event *event)
{
    static Board gameboard;

    event->doAction(gameboard);

    glutPostRedisplay();

    delete event;
}

/***************************************************************************//**
 * Initialize glut callback functions, set the display mode, create a window
 ******************************************************************************/
void initOpenGL(int argc, char** argv, int wCols, int wRows)
{
    glutInit(&argc, argv);

    // Choose the display mode for the window.  GLUT_DOUBLE means double 
    // buffering, GLUT_RGBA is 24-bit color with 8-bit alpha

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    // Set window size and position
    glutInitWindowSize(wCols, wRows);

    glutInitWindowPosition(100, 100);

    glutCreateWindow(argv[0]);

    // Subscribe to GLUT events

    glutDisplayFunc(display);

    glutKeyboardFunc(keyboard);

    glutMouseFunc(mouseClick);

    glutPassiveMotionFunc(mouseMove);

    glutReshapeFunc(reshape);

    utilityCentral(new GameStart());
    // This is the color which will be used to clear the display / back plane
    // when glClear() is called
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}
