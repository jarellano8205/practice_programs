#include "telem.h"
#include <stdlib.h> // included for: std::cout << fixed
#include <time.h> // included for: srand time(0)

int main(int argc, char *argv[])
{
   StopWatch sw;
   srand (time(0));
   std::ofstream numberOutputFile;
   std::stringstream sstream;

   numberOutputFile.open("numberOutput");
   
   sw.start("create integer array 20 elements all set to 0");

   int numberArray[20] = {0};

   sw.stop();
   sw.reportToFile("output");
   sw.reset();
   
   sw.start("create integer array 200 elements all set to 0");

   int numberArrayTwo[200] = {0};

   sw.stop();
   sw.reportToFile("output");
   sw.reset();
   
   sw.start("create integer array 2000 elements and gen. random numbers");

   int numberArrayThree[2000] = {0};

   for (int i = 0 ; i < 2000 ; i++)
   {
      numberArrayThree[i] = rand() % 10000;
   }

   sw.stop();
   sw.reportToFile("output");
   sw.reset();

   sw.start("print 2000 random numbers into numberOutput file");

   for (int i = 0 ; i < 2000 ; i++)
   {
      numberOutputFile << numberArrayThree[i] << "\n";
   }
   numberOutputFile << std::endl;
   numberOutputFile.close();

   sw.stop();
   sw.reportToFile("output");
   sw.reset();

   sstream = sw.reportToSS();
   std::cout << sstream.str().c_str();
   return 0;
}
