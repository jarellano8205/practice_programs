#include "telemDisplay.h"
#include "twoSum.h"

TelemDisplay::TelemDisplay() {}

void TelemDisplay::displayTasks()
{
   int x = 15;
   int x2 = 215;
   int y = (glutGet(GLUT_WINDOW_HEIGHT));
   int y2 = (glutGet(GLUT_WINDOW_HEIGHT)) - 15;
   glClear(GL_COLOR_BUFFER_BIT);

   DrawFilledRectangle(10, glutGet(GLUT_WINDOW_HEIGHT) - 10, 400, 10, DarkGray);

   for (auto items : completedTasks)
   {
      y -= 25;

      if (y < 25)
      {
         resetTaskList();
      }

      DrawTextString(items, x, y, Orange);
   }

   for (auto items : importedTasks)
   {
      x2 += 200;

      if (x2 >= glutGet(GLUT_WINDOW_WIDTH) - 200)
      {
         x2 = 400;
      }
      DrawTextString(items.first, x2, y2, Orange);
      DrawTextString(std::to_string(items.second.size()), x2 + 200, y2, Orange);

      for (auto timePoint : items.second)
      {
         y2 -= 25;
         DrawTextString(std::to_string(timePoint), x2, y2, Orange);

         if (y2 <= 15)
         {
            y2 = glutGet(GLUT_WINDOW_HEIGHT) - 15;
            x2 += 75;
         }
      }
   }

   glutSwapBuffers();
}

void TelemDisplay::addTask()
{
   StopWatch task;
   std::stringstream report;

   task.start("two sum algorithm");

   std::vector<int> numbers = {2, 7, 11, 15};
   std::vector<int> solution;
   int target = 9;

   try
   {
      solution = (addNumbers(numbers, target));
      /*std::cout << "elements that sum = target: ";

      for (auto items : solution)
      {
         std::cout << items << " ";
      }
      std::cout << std::endl;*/
   }
   catch(const char* error)
   {
      std::cout << error << std::endl;
   }

   task.stop();
   task.reportToFile("output");
   // set reportStringStream to formatted string stream then push it as a string
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

   importedTasks.clear();
 
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
         // grabs the task description and time from the import data file then
         // converts the string into a double to push it on the vector of time
         // points for the task.
         timeCompleted = stod(taskTime);

         importedTasks[taskDescription].push_back(timeCompleted);

         importFile.ignore(1, 's');
      }
      importFile.close();
   }
   catch(const char *error)
   {
      std::cout << error << std::endl;
   }
}
