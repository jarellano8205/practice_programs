#include "telemDisplay.h"

TelemDisplay::TelemDisplay() {}

void TelemDisplay::displayTasks()
{
   int x = 5;
   int x2 = 200;
   int x3 = 335;
   int y = (glutGet(GLUT_WINDOW_HEIGHT));
   int y2 = (glutGet(GLUT_WINDOW_HEIGHT)) - 15;
   int y3 = (glutGet(GLUT_WINDOW_HEIGHT)) - 30;
   glClear(GL_COLOR_BUFFER_BIT);

   for (auto items : completedTasks)
   {
      y -= 15;

      if (y < 15)
      {
         resetTaskList();
      }

      DrawTextString(items, x, y, Orange);
   }

   for (auto items : tasks)
   {
      x2 += 200;

      if (x2 >= glutGet(GLUT_WINDOW_WIDTH) - 200)
      {
         x2 = 400;
      }
      DrawTextString(items.first, x2, y2, Orange);
      DrawTextString(std::to_string(items.second.size()), x2 + 160, y2, Orange);
      
      for (auto second : items.second)
      {
         x3 += 65;

         if (x3 >= glutGet(GLUT_WINDOW_WIDTH) - 40)
         {
            y3 -= 20;
            x3 = 400;
         }
         DrawTextString(std::to_string(second) + "s", x3, y3, Orange);
      } 
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

void TelemDisplay::resetTaskList()
{
   completedTasks.clear();
}

void TelemDisplay::importTaskData()
{
   std::ifstream importFile;
   std::string taskDescription;
   std::string taskTime;
   double timeCompleted = 0.0;

   tasks.clear();
 
   try
   {

      importFile.open("output");

      if (!importFile.is_open())
      {
         importFile.close();
         throw "error opening import data file";
      }

      while (!importFile.eof())
      {
         getline(importFile, taskDescription);
         getline(importFile, taskTime, 's');

         timeCompleted = stod(taskTime);

         tasks[taskDescription].push_back(timeCompleted);

         importFile.ignore(1, 's');
      }
      importFile.close();
   }
   catch(const char *error)
   {
      std::cout << error << std::endl;
   }
}
