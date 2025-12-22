#pragma once
#include "student.h"
#include <vector>

class SortManager {
public:
    // Strategy 1: copy into two new containers
    static void splitCopy(const std::vector<Student>& students,
                          std::vector<Student>& passed,
                          std::vector<Student>& failed);

    // Strategy 2: move failed students out of the base container
    static void splitMove(std::vector<Student>& students,
                          std::vector<Student>& failed);
};
