#ifndef TELEM_H
#define TELEM_H
#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class StopWatch
{
   std::chrono::system_clock::time_point startTime;
   
   std::chrono::duration<double> taskDuration =
   std::chrono::duration<double>::zero();
   
   std::string taskDescription = "";
   std::time_t timeCompleted;
public:
   StopWatch();
   void start(std::string description);
   void stop();
   void reset(); 
   double reportDuration(); 
   void reportToConsole();
   void reportToFile(std::string fileName);
   std::stringstream reportToSS(); 
};

#endif
