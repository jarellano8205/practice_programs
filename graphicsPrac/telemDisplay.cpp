#include "telemDisplay.h"

TelemDisplay::TelemDisplay() {}

void TelemDisplay::displayTime()
{
   StopWatch task;
   std::stringstream report;
   task.start("create int array");
   
   int numberArray[1000] = {0};

   task.stop();

   report = task.reportSS();
   
   glClear(GL_COLOR_BUFFER_BIT);
   DrawTextString(report.str().c_str(), glutGet(GLUT_WINDOW_WIDTH)/2,
   glutGet(GLUT_WINDOW_HEIGHT)/2, Green);
   glutSwapBuffers();
}
