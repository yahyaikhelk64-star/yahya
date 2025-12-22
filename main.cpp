#include <iostream>
#include <algorithm>
#include "FileManager.h"
#include "StudentProcessor.h"
#include "Timer.h"

int main() {
    try {
        FileManager::generate("students.txt", 10000);

        Timer total;

        Timer t1;
        auto students = FileManager::read("students.txt");
        std::cout << "Read: " << t1.elapsed() << " s\n";

        Timer t2;
        std::sort(students.begin(), students.end());
        std::cout << "Sort: " << t2.elapsed() << " s\n";

        std::vector<Student> passed, failed;
        Timer t3;
        StudentProcessor::split(students, passed, failed);
        std::cout << "Split: " << t3.elapsed() << " s\n";

        Timer t4;
        FileManager::write("passed.txt", passed);
        FileManager::write("failed.txt", failed);
        std::cout << "Write: " << t4.elapsed() << " s\n";

        std::cout << "Total: " << total.elapsed() << " s\n";
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}
