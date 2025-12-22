#include "sort_manager.h"
#include <algorithm>

void SortManager::splitCopy(const std::vector<Student>& students,
                            std::vector<Student>& passed,
                            std::vector<Student>& failed) {
    passed.clear();
    failed.clear();
    std::copy_if(students.begin(), students.end(), std::back_inserter(passed),
                 [](const Student& s){ return s.grade >= 5.0; });
    std::copy_if(students.begin(), students.end(), std::back_inserter(failed),
                 [](const Student& s){ return s.grade < 5.0; });
}

void SortManager::splitMove(std::vector<Student>& students,
                            std::vector<Student>& failed) {
    failed.clear();
    auto it = std::partition(students.begin(), students.end(),
                             [](const Student& s){ return s.grade >= 5.0; });
    failed.assign(it, students.end());
    students.erase(it, students.end());
}
