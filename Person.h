#ifndef PERSON_H
#define PERSON_H

#include "Libraries.h"

class Person {
public:
    std::string name;
    std::string surname;
    std::vector<int> homeworks;
    int exam;
    double finalGrade;

    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    void calculateFinal(bool useMedian);
    void display() const;
};

#endif
