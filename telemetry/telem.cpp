#include "telem.h"

StopWatch::StopWatch()
{}

void StopWatch::start(std::string description)
{
   startTime = std::chrono::system_clock::now();
   taskDescription = description;
}

void StopWatch::stop()
{
   taskDuration += std::chrono::system_clock::now() - startTime;
   
   timeCompleted =
   std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void StopWatch::reset()
{
   taskDuration = std::chrono::duration<double>::zero();
}

double StopWatch::reportDuration()
{
   return double(taskDuration.count());
}
void StopWatch::reportToConsole()
{
   std::cout << "completed " << taskDescription << std::endl;
   std::cout << std::fixed << taskDuration.count() << "s\t\t" 
      << std::ctime(&timeCompleted) << std::endl;
}

void StopWatch::reportToFile(std::string fileName)
{
   std::ofstream report;
   try
   { 
      report.open(fileName, std::ios::app);

      if (!report.is_open())
      {
         throw "error opening file"; 
      }
   }
   catch(const char* error)
   {
      std::cout << error << std::endl;
   }
   report << "completed " << taskDescription << std::endl;
   report << std::fixed << taskDuration.count() << "s\t\t"
          << std::ctime(&timeCompleted) << std::endl;
   report.close();
}

std::stringstream StopWatch::reportToSS()
{
   std::stringstream ss;
   ss << "completed " << taskDescription << std::endl;
   ss << std::fixed << taskDuration.count() << "s\t\t" 
      << std::ctime(&timeCompleted) << std::endl;

   return ss;
}
