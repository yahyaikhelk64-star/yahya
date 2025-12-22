#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Student.h"

class FileManager {
public:
    static void generate(const std::string&, size_t);
    static std::vector<Student> read(const std::string&);
    static void write(const std::string&, const std::vector<Student>&);
};

#endif
