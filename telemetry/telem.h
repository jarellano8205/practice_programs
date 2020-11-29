#ifndef TELEM_H
#define TELEM_H
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

class StopWatch
{
   std::chrono::system_clock::time_point timeLoc;
   std::chrono::duration<double> dur;
   std::string taskDescription = "";
public:
   StopWatch();
   void start(std::string descr);
   void stop();
   void reset(); 
   void report();
   
};

#endif
