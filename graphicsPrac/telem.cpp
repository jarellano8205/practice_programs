#include "telem.h"

StopWatch::StopWatch()
{}

void StopWatch::start(std::string descr)
{
   timeLoc = std::chrono::system_clock::now();
   taskDescription = descr;
}

void StopWatch::stop()
{
   dur += std::chrono::system_clock::now() - timeLoc;
   timeCompleted = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

void StopWatch::reset()
{
   dur = std::chrono::duration<double>::zero();
}

void StopWatch::report()
{
   std::cout << "completed " << taskDescription << std::endl;
   std::cout << std::fixed << dur.count() << "s\t\t" 
             << std::ctime(&timeCompleted) << std::endl;
}

void StopWatch::reportToFile(std::string fileName)
{
   std::ofstream report;
   
   report.open(fileName, std::ios::app);

   if(!report.is_open())
   {
      std::cout << "error opening file::" << fileName << std::endl;
      exit(1);
   }

   report << "completed " << taskDescription << std::endl;
   report << std::fixed << dur.count() << "s\t\t"
          << std::ctime(&timeCompleted) << std::endl;
   report.close();
}

std::stringstream StopWatch::reportSS()
{
   std::stringstream ss;
   ss << "completed " << taskDescription << std::endl;
   ss << std::fixed << dur.count() << "s\t\t" 
      << std::ctime(&timeCompleted) << std::endl;

   return ss;
}
