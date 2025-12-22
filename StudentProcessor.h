#ifndef STUDENTPROCESSOR_H
#define STUDENTPROCESSOR_H

#include <vector>
#include "Student.h"

class StudentProcessor {
public:
    static void split(const std::vector<Student>&,
                      std::vector<Student>&,
                      std::vector<Student>&);
};

#endif
