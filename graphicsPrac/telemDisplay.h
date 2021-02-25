#ifndef TELEMDISPLAY_H
#define TELEMDISPLAY_H
#include <GL/freeglut.h>
#include "graphics.h"
#include "telem.h"
#include <vector>
#include <map>

class TelemDisplay
{
   std::vector<std::string> completedTasks;
   std::map<std::string, std::vector<double>> importedTasks;
public:
   TelemDisplay();

   void displayTasks();
   void addTask();
   void resetTaskList();
   void importTaskData();
};

#endif
