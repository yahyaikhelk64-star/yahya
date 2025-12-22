#include "student.h"
#include "file_manager.h"
#include "sort_manager.h"
#include <vector>
#include <chrono>
#include <iostream>

int main() {
    try {
        std::vector<Student> students;
        FileManager::readStudents("students.txt", students);

        std::vector<Student> passed, failed;

        // Strategy 1: splitCopy
        auto start = std::chrono::high_resolution_clock::now();
        SortManager::splitCopy(students, passed, failed);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "SplitCopy time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";

        FileManager::writeStudents("passed.txt", passed);
        FileManager::writeStudents("failed.txt", failed);

        // Strategy 2: splitMove
        FileManager::readStudents("students.txt", students);
        start = std::chrono::high_resolution_clock::now();
        SortManager::splitMove(students, failed);
        end = std::chrono::high_resolution_clock::now();
        std::cout << "SplitMove time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    return 0;
}
