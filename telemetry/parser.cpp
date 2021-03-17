#include "parser.h"

std::map<std::string, std::vector<double>> parseData( std::string dataFileName )
{
   std::map<std::string, std::vector<double>> importedData;
   std::ifstream importFile;
   std::string taskDescription;
   std::string taskDuration;
   double timeCompleted = 0.0;

   importFile.open(dataFileName);

   if ( !importFile.is_open() )
   {
      exit(1);
   }

   while ( !importFile.eof() )
   {
      getline( importFile, taskDescription );
      getline( importFile, taskDuration, 's' );

      timeCompleted = stod( taskDuration );

      importedData[ taskDescription ].push_back( timeCompleted );

      importFile.ignore( 1, 's' );
      importFile.ignore( 256, '\n' );
      importFile.ignore( 256, '\n' );
   }

   importFile.close();

   return importedData;
}
