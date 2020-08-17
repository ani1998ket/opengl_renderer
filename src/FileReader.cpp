#include "FileReader.hpp"

#include <iostream>
#include <fstream>
#include <sstream>


void FileReader::read_text_file(std::string path, std::string& destination){
    std::ifstream file( path );
    if(!file){
        std::cerr << "File not found\n";
        exit(-1);
    }
    getline(file, destination, '\0');
    file.close();
}
