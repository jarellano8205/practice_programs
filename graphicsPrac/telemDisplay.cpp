#include "telemDisplay.h"

TelemDisplay::TelemDisplay() {}

void TelemDisplay::displayTime()
{
   StopWatch task;

   task.start("create int array");
   
   int numberArray[1000] = {0};

   task.stop();
   std::string reportString = "";
   reportString = task.report();
   glClear(GL_COLOR_BUFFER_BIT);
   DrawTextString(reportString, glutGet(GLUT_WINDOW_WIDTH)/2,
   glutGet(GLUT_WINDOW_HEIGHT)/2, Green);
   glutSwapBuffers();
}
