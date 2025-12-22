#include "file_manager.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

void FileManager::readStudents(const std::string& filename, std::vector<Student>& students) {
    std::ifstream file(filename);
    if (!file) throw std::runtime_error("Cannot open file: " + filename);

    students.clear();
    std::string name, surname;
    double grade;
    while (file >> name >> surname >> grade) {
        students.emplace_back(name, surname, grade);
    }
}

void FileManager::writeStudents(const std::string& filename, const std::vector<Student>& students) {
    std::ofstream file(filename);
    if (!file) throw std::runtime_error("Cannot write to file: " + filename);

    for (const auto& s : students)
        file << s.name << " " << s.surname << " " << s.grade << "\n";
}
