#include "Student.h"

Student::Student() : finalScore(0.0) {}

Student::Student(const std::string& n, const std::string& s, double score)
    : name(n), surname(s), finalScore(score) {}

bool Student::operator<(const Student& other) const {
    return finalScore < other.finalScore;
}
