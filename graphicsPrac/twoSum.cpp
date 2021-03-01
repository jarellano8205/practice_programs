#include "twoSum.h"

std::vector<int> addNumbers(std::vector<int> &numbers, int target)
{
   for (unsigned int i = 0 ; i < numbers.size() ; i++)
   {
      for (unsigned int j = 1 ; j < numbers.size() ; j++)
      {
         if (i != j && numbers[j] == target - numbers[i])
         {
            std::vector<int> elements;
            elements.push_back(i);
            elements.push_back(j);
            return elements;
         }
      }
   }
   throw "not found";
}   
