#pragma once
#include "student.h"
#include <vector>
#include <string>

class FileManager {
public:
    static void readStudents(const std::string& filename, std::vector<Student>& students);
    static void writeStudents(const std::string& filename, const std::vector<Student>& students);
};
