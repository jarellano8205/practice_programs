#ifndef TELEMTEST
#define TELEMTEST

#include <catch2/catch.hpp> 
#include "telem.h"

TEST_CASE("create StopWatch object")
{
   StopWatch *clock = nullptr;

   clock = new(std::nothrow)StopWatch;

   REQUIRE(clock != nullptr);

   delete clock;
}

TEST_CASE("reportDuration returns duration as a double")
{
   StopWatch clock;

   double time = 0.0;

   clock.start("test timer");
   clock.stop();

   time = clock.reportDuration();

   REQUIRE(time >= 0);
}

TEST_CASE("reset returns duration to zero")
{
   StopWatch clock;

   double time = 0.0;

   clock.start("another test timer");

   int *testNumbers = nullptr;

   testNumbers = new(std::nothrow)int[200];

   delete [] testNumbers;

   clock.stop();
   clock.reset();

   time = clock.reportDuration();

   REQUIRE(time == 0);
}

#endif
