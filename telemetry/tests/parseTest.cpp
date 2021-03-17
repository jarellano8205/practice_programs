#ifndef PARSETEST
#define PARSETEST

#include <catch2/catch.hpp>
#include "../parser.h"

TEST_CASE( "Parse the provided output file", "[parse]" )
{
   std::string firstKey =
   "completed create integer array 20 elements all set to 0";

   std::string secondKey =
   "completed create integer array 200 elements all set to 0";

   std::string thirdKey =
   "completed create integer array 2000 elements and gen. random numbers";

   std::string fourthKey =
   "completed print 2000 random numbers into numberOutput file";
 
   std::map< std::string, std::vector<double> > impData;

   impData = parseData( "output" );

   REQUIRE ( impData[ firstKey ].at( 0 ) == 0.000003 );

   REQUIRE ( impData[ secondKey ].at( 0 ) == 0.000001 );

   REQUIRE ( impData[ thirdKey ].at( 0 ) == 0.000149 );

   REQUIRE ( impData[ fourthKey ].at( 0 ) == 0.000794 ); 
}

#endif
