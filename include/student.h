#pragma once
#include <string>

class Student {
public:
    std::string name;
    std::string surname;
    double grade;

    Student() : name(""), surname(""), grade(0.0) {}
    Student(const std::string& n, const std::string& s, double g)
        : name(n), surname(s), grade(g) {}
};
