#include "FileManager.h"
#include <fstream>
#include <stdexcept>
#include <cstdlib>

void FileManager::generate(const std::string& file, size_t n) {
    std::ofstream out(file);
    if (!out) throw std::runtime_error("Cannot create file");

    for (size_t i = 1; i <= n; ++i)
        out << "Name" << i << " Surname" << i << " "
            << (rand() % 1000) / 100.0 << "\n";
}

std::vector<Student> FileManager::read(const std::string& file) {
    std::ifstream in(file);
    if (!in) throw std::runtime_error("File not found");

    std::vector<Student> v;
    std::string n, s;
    double f;

    while (in >> n >> s >> f)
        v.emplace_back(n, s, f);

    return v;
}

void FileManager::write(const std::string& file,
                        const std::vector<Student>& v) {
    std::ofstream out(file);
    if (!out) throw std::runtime_error("Cannot write file");

    for (auto& s : v)
        out << s.name << " " << s.surname << " " << s.finalScore << "\n";
}
