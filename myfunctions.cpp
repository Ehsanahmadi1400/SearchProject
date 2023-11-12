
#include <iostream>
#include <string>
#include <cstring>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if a given path corresponds to a directory
bool isDirectory(const std::string& path) {

    // Declare a struct to hold file status information
    struct stat statbuf;

    // Use the stat function to retrieve file status for the specified path
    // If the function fails, return false, indicating the path is not a directory
    if (stat(path.c_str(), &statbuf) != 0) {
        return false;
    }

    // Check if the file mode indicates that the path corresponds to a directory
    // Returns true if it is a directory, false otherwise
    return S_ISDIR(statbuf.st_mode);
}

// Function to search for a specified text in file names within a given directory and its subdirectories
bool searchAndPrint(const std::string& searchText, const std::string& directory) {

    bool status;
    // Open the specified directory for reading
    DIR* dir = opendir(directory.c_str());

    // Check if the directory was opened successfully
    if (dir != nullptr) {

        // Declare a structure to hold directory entry information
        struct dirent* entry;

        // Iterate through directory entries
        while ((entry = readdir(dir)) != nullptr) {
            // Construct the full path of the current entry
            std::string path = directory + "/" + entry->d_name;

            // Check if the entry is a directory
            if (isDirectory(path)) {
                // Recursively search subdirectories, excluding "." and ".."        
                if (std::strcmp(entry->d_name, ".") != 0 && std::strcmp(entry->d_name, "..") != 0) {
                    searchAndPrint(searchText, path);
                }
            } else {

                // If the entry is a file, check if the filename contains the specified search text
                std::string filename = entry->d_name;
                if (filename.find(searchText) != std::string::npos) {
                    // Print the path if the search text is found in the file name
                    std::cout << "Found in file: " << path << std::endl;
                }

            }
        }

        status = true;
        // Close the directory after processing all entries
        closedir(dir);
    } 
    else {
        // Print an error message if the directory couldn't be opened
        std::cerr << "Error opening directory: " << directory << std::endl;
        status = false;
    }
    return status;
}
