#include "StudentProcessor.h"

void StudentProcessor::split(const std::vector<Student>& all,
                             std::vector<Student>& pass,
                             std::vector<Student>& fail) {
    for (auto& s : all)
        (s.finalScore < 5.0 ? fail : pass).push_back(s);
}
