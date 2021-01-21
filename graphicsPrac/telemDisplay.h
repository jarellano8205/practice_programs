#ifndef TELEMDISPLAY_H
#define TELEMDISPLAY_H
#include <GL/freeglut.h>
#include "graphics.h"
#include "telem.h"
#include <vector>

class TelemDisplay
{
   std::vector<std::string> completedTasks;
public:
   TelemDisplay();

   void displayTasks();
   void addTask();
};

#endif
