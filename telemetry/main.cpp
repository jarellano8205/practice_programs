#include "telem.h"

int main(int argc, char *argv[])
{
   StopWatch sw;

   sw.start("create integer array 20 elements all set to 0");

   int numberArray[20] = {0};
   
   sw.stop();

   sw.report();

   sw.reset();

   sw.start("create integer array 200 elements all set to 0");

   int numberArrayTwo[200] = {0};

   sw.stop();

   sw.report();

   sw.reset();

   sw.start("create integer array 2000 elements all set to 0");

   int numberArrayThree[2000] = {0};

   sw.stop();

   sw.report();

   sw.reset();

   return 0;
}
