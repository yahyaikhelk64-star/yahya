#include "Libraries.h"
#include "Person.h"

int main() {
    std::ifstream file("Students.txt");
    if (!file) {
        std::cout << "Error: cannot open Students.txt\n";
        return 1;
    }

    std::vector<Person> students;
    std::string name, surname;

    while (file >> name >> surname) {
        Person p;
        p.name = name;
        p.surname = surname;

        std::vector<int> allGrades;
        int grade;

        std::string line;
        std::getline(file, line);
        std::istringstream iss(line);
        while (iss >> grade) {
            allGrades.push_back(grade);
        }

        if (!allGrades.empty()) {
            p.exam = allGrades.back();
            allGrades.pop_back();
            p.homeworks = allGrades;
        }

        p.calculateFinal(false);
        students.push_back(p);
    }

    std::sort(students.begin(), students.end(),
              [](const Person& a, const Person& b) {
                  return a.surname < b.surname;
              });

    std::cout << "\nName       Surname        Final (Avg.) | Final (Med.)\n";
    std::cout << "----------------------------------------------------\n";

    for (auto &s : students) {
        s.calculateFinal(false);
        double avg = s.finalGrade;
        s.calculateFinal(true);
        double med = s.finalGrade;

        std::cout << std::left << std::setw(10) << s.name
                  << std::setw(12) << s.surname
                  << std::setw(10) << std::fixed << std::setprecision(2) << avg
                  << " | "
                  << std::setw(10) << std::fixed << std::setprecision(2) << med
                  << std::endl;
    }

    return 0;
}
