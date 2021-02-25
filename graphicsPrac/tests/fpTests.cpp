#ifndef FPTESTS
#define FPTESTS

#include "catch.hpp"
#include "../telem.h"

TEST_CASE("stopwatch can be made")
{
   int x = 0;
   StopWatch clock;
   clock.start("hello");
   clock.stop();
   clock.report();
   clock.reset();

   REQUIRE(x == 0);
}

#endif
