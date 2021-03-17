#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <map>
#include <vector>
#include <string>

std::map<std::string, std::vector<double>> parseData( std::string dataFileName );

#endif
