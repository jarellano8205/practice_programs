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
   DrawTextString(report.str().c_str(), 5, 460, Green);
   task.reset();
   task.start("assign numbers to array");

   for(int i = 0; i < 1000 ; i++)
   {
      numberArray[i] = i;
   }

   task.stop();
   report = task.reportSS();
   DrawTextString(report.str().c_str(), 5, 445, Green);
   task.reset();

   task.start("some other task");
   std::string someString = "hello there";
   task.stop();
   report = task.reportSS();
   DrawTextString(report.str().c_str(), 5, 430, Green);
   task.reset();

   glutSwapBuffers();
}
