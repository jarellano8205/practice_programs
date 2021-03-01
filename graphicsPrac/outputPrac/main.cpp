#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>

int main(int argc, char *argv[])
{
   std::ifstream data;
   std::string inputString;
   std::string timeString;
   double taskTime = 0.0;
   std::map<std::string, std::vector<double>> taskFrequency;

   try
   {
      data.open("output");

      if (!data.is_open())
      {
         data.close();
         throw "error opening data file";
      }

      while (!data.eof())
      {
         getline(data, inputString);
         getline(data, timeString, 's');
         
         taskTime = stod(timeString);

         taskFrequency[inputString].push_back(taskTime);

         data.ignore(1, 's');         
      }

      for (auto items : taskFrequency)
      {
         for (auto first : items.first)
         {
            std::cout << first;
         }
         std::cout << ": " << items.second.size() << " instance(s)";

         std::cout << std::endl;

         for (auto second : items.second)
         {
            static int columns = 0;
            std::cout << std::fixed << second << "s ";
            columns++;

            if (columns == 2)
            {
               std::cout << std::endl;
               columns = 0;
            } 
         }

         std::cout << std::endl;
      }
      data.close();
   }
   catch(const char *error)
   {
      std::cout << error << std::endl;
   }


   return 0;
}
