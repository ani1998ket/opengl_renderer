#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <string>

class FileReader{
    private:
    FileReader() = delete;
    ~FileReader() = delete;

    public:
    static void read_text_file(std::string filename, std::string& destination );
};
#endif