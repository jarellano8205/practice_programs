#include "telem.h"
#include "parser.h"

int main( int argc, char *argv[])
{
   std::ofstream exportParse;
   std::map<std::string, std::vector<double>> importedData;
   double averageDuration = 0.0;

   importedData = parseData("output");

   exportParse.open("fParseOutput.txt");

   if ( !exportParse.is_open() )
   {
      exit(1);
   }

   for ( auto items : importedData )
   {
      exportParse << items.first << " , count: " << items.second.size() << "\n";

      for ( auto timePoint : items.second )
      {
         averageDuration += timePoint;
      }

      averageDuration = averageDuration / items.second.size();

      exportParse << "Average duration: " << std::fixed << averageDuration 
      << "\n\n";
   }

   exportParse.close();

   return 0;
}
