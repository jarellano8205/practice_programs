#ifndef TELEMTEST
#define TELEMTEST

#include <catch2/catch.hpp> 
#include "telem.h"

TEST_CASE("create StopWatch object")
{
   StopWatch *clock = nullptr;
   double time = 0.0;

   clock = new(std::nothrow)StopWatch;

   REQUIRE(clock != nullptr);

   time = clock->reportDuration();

   REQUIRE(time == 0);

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

   clock.start("test timer");

   int *testNumbers = nullptr;

   testNumbers = new(std::nothrow)int[200];

   delete [] testNumbers;

   clock.stop();
   clock.reset();

   time = clock.reportDuration();

   REQUIRE(time == 0);
}

TEST_CASE("reportToSS returns the report for the task as a string stream")
{
   StopWatch clock;
   std::stringstream testStream;
   std::string testString = "";

   clock.start("test timer");

   int *testNumbers = nullptr;

   testNumbers = new(std::nothrow)int[200];

   delete [] testNumbers;

   clock.stop();

   testStream = clock.reportToSS();
 
   testString = testStream.str();
 
   REQUIRE(testString.size() > 0);
}
   
#endif
