#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    std::string name;
    std::string surname;
    double finalScore;

    Student();
    Student(const std::string& n, const std::string& s, double score);

    bool operator<(const Student& other) const;
};

#endif
