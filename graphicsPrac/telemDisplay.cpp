#include "telemDisplay.h"
#include <iostream>

TelemDisplay::TelemDisplay() {}

void TelemDisplay::displayTasks()
{
   int y = 485;
   glClear(GL_COLOR_BUFFER_BIT);
   for (auto items : completedTasks)
   {
      y -= 15; 
      DrawTextString(items, 5, y, Green);
   }
   glutSwapBuffers();
}

void TelemDisplay::addTask()
{
   StopWatch task;
   std::stringstream report;

   task.start("some task");
   int a = 5;
   task.stop();
   report = task.reportSS();
   completedTasks.push_back(report.str());
   task.reset();
}
