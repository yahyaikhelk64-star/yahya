#include "Person.h"

Person::Person() : exam(0), finalGrade(0.0) {}

Person::Person(const Person& other) = default;

Person& Person::operator=(const Person& other) = default;

Person::~Person() = default;

void Person::calculateFinal(bool useMedian) {
    if (homeworks.empty()) {
        finalGrade = 0.0;
        return;
    }

    double result = 0.0;
    if (useMedian) {
        std::vector<int> sorted = homeworks;
        std::sort(sorted.begin(), sorted.end());
        size_t mid = sorted.size() / 2;
        if (sorted.size() % 2 == 0)
            result = (sorted[mid - 1] + sorted[mid]) / 2.0;
        else
            result = sorted[mid];
    } else {
        result = std::accumulate(homeworks.begin(), homeworks.end(), 0.0) / homeworks.size();
    }

    finalGrade = 0.4 * result + 0.6 * exam;
}

void Person::display() const {
    std::cout << std::left << std::setw(10) << name
              << std::setw(12) << surname
              << std::setw(10) << std::fixed << std::setprecision(2) << finalGrade
              << std::endl;
}
