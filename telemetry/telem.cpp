#include "telem.h"

StopWatch::StopWatch()
{}

void StopWatch::start()
{
   timeLoc = std::chrono::system_clock::now();
}

void StopWatch::stop()
{
   dur += std::chrono::system_clock::now() - timeLoc;
}

void StopWatch::reset()
{
   dur = std::chrono::duration<double>::zero();
   point = dur;
}

void StopWatch::report()
{
   std::cout << std::fixed << dur.count() << "s" << std::endl;
}
