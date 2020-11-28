#include "telem.h"

int main(int argc, char *argv[])
{
   StopWatch sw;

   sw.start();

   int numberArray[20] = {0};
   
   sw.stop();

   sw.report();

   sw.reset();

   return 0;
}
