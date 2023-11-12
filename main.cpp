/*
*** This program receives a name and a path, then finds
*** similiar file names with the name in the specified path
*** Author: Ehsan Ahmadi 12.11.2023
*/

#include <iostream>
#include <string>
#include <cstring>  // For std::system
// #include <dirent.h>
#include <sys/stat.h>
#include "header.h"

std::string name, path;

int main() {

    // Get user input for the text to search and the path
    std::cout << "Please enter the name you want to be found: ";
    std::getline(std::cin, name);

    std::cout << "Now enter the path with proper \\ signs: ";
    std::getline(std::cin, path);

    std::cout << "Searching ... \n" << std::endl;

    // Search for the text in the specified path hereunder
    if (!searchAndPrint(name, path)) {
        std::cerr << "Error during search or no similar files found." << std::endl;
    }

    // Search for the text in the specified path hereunder
    searchAndPrint(name, path);  

    std::cout << "\nSearch is over  " << std::endl;
    std::cout << "In case nothing is shown, it means no similar files were found " << std::endl;
    std::cout << "You can now close the window " << std::endl;

    std::system("pause");
    return 0;
}

