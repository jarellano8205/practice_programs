#include "telemDisplay.h"

TelemDisplay::TelemDisplay() {}

void TelemDisplay::displayTasks()
{
   int x = 5;
   int y = (glutGet(GLUT_WINDOW_HEIGHT));

   glClear(GL_COLOR_BUFFER_BIT);

   for (auto items : completedTasks)
   {
      y -= 15;

      if (y < 15)
      {
         resetTasks();
      }

      DrawTextString(items, x, y, Orange);
   }

   glutSwapBuffers();
}

void TelemDisplay::addTask()
{
   StopWatch task;
   std::stringstream report;

   task.start("some task");
   int a = 5;
   a += 5;
   task.stop();
   task.reportToFile("output");
   report = task.reportSS();
   completedTasks.push_back(report.str());
   task.reset();
}

void TelemDisplay::resetTasks()
{
   completedTasks.clear();
}
