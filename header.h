#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <string>

extern std::string name, path;

// Function declarations
bool isDirectory(const std::string& path);
bool searchAndPrint(const std::string& searchText, const std::string& directory);



#endif // FUNCTIONS_H