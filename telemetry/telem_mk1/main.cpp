#include <chrono>
#include <fstream>
#include <iomanip>
#include <iostream>

int main(int argc, char *argv[])
{
   std::ofstream output;
   
   output.open("output", std::ios::app);

   int numbers[10] = {0};

   // start of the telemetry block --------------------------------------------

   // start ------------------------------------
   auto startTime = std::chrono::system_clock::now();
   // -----------------------------------------
   for (int i = 0 ; i < 10 ; i++)
   {
      numbers[i] = i;  
   }
   // end -------------------------------------
   auto endTime = std::chrono::system_clock::now();
   // -----------------------------------------

   // time calc -------------------------------
   std::chrono::duration<double> difference = endTime - startTime;
   std::time_t timeCompleted = std::chrono::system_clock::to_time_t(endTime);
   // -----------------------------------------

   // output info -----------------------------
   std::cout << "completed: assign value 'i' to array of numbers::" <<
   std::ctime(&timeCompleted);
   std::cout << std::fixed << difference.count() << "s" << std::endl;
   std::cout << std::endl;
   // -----------------------------------------
   
   // output info -----------------------------
   output << "completed: assign value 'i' to array of numbers::" <<
   std::ctime(&timeCompleted);
   output << std::fixed << difference.count() << "s" << std::endl;
   output << std::endl;
   // -----------------------------------------

   // end of the telemetry block ----------------------------------------------

   // start of the telemetry block --------------------------------------------
   
   // start ------------------------------------ 
   startTime = std::chrono::system_clock::now();
   // ------------------------------------------
   
   for (int w : numbers)
   {
      std::cout << w << "\n";
   }

   // end --------------------------------------
   endTime = std::chrono::system_clock::now();
   // ------------------------------------------

   // time calc --------------------------------
   difference = endTime - startTime;
   timeCompleted = std::chrono::system_clock::to_time_t(endTime);
   // ------------------------------------------

   // output info ------------------------------
   std::cout << "completed: print array of numbers::" << 
   std::ctime(&timeCompleted);
   std::cout << std::fixed << difference.count() << "s" << std::endl;
   std::cout << std::endl;
   // ------------------------------------------

   // output info ------------------------------
   output << "completed: print array of numbers::" <<
   std::ctime(&timeCompleted);
   output << std::fixed << difference.count() << "s" << std::endl;
   output << std::endl;
   // ------------------------------------------
   // end of the telemetry block ----------------------------------------------

   return 0;
}
