#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
    std::chrono::high_resolution_clock::time_point start;
public:
    Timer();
    double elapsed() const;
};

#endif
