#include <iostream>

int main(int argc, char *argv[])
{
   try
   {
      int number = 5;
      if (number == 5)
      {
         std::cout << "Hello Five" << std::endl;
      }
      else
      {
         throw 101;
      }
   }
   catch(...)
   {
      std::cout << "Access Denied" << std::endl;
   }

   return 0;
}
