#ifndef TELEM_H
#define TELEM_H
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class StopWatch
{
   std::chrono::system_clock::time_point timeLoc;
   std::chrono::duration<double> dur;
   std::string taskDescription = "";
   std::time_t timeCompleted;
public:
   StopWatch();
   void start(std::string descr);
   void stop();
   void reset(); 
   void report();
   void reportToFile(std::string fileName);
   std::stringstream reportSS(); 
};

#endif
