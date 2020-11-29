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
}

void StopWatch::reset()
{
   dur = std::chrono::duration<double>::zero();
}

void StopWatch::report()
{
   std::cout << "completed " << taskDescription << std::endl;
   std::cout << std::fixed << dur.count() << "s" << std::endl;
}
