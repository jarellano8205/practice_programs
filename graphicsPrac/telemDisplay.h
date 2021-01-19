#ifndef TELEMDISPLAY_H
#define TELEMDISPLAY_H
#include <iostream>
#include <sstream>
#include <string>
#include <GL/freeglut.h>
#include "graphics.h"
#include "telem.h"

class TelemDisplay
{
   std::string taskTime = "";
public:
   TelemDisplay();

   void displayTime();
};

#endif
