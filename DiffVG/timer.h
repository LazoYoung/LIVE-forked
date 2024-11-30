#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <functional>

template<typename TimeUnit = std::chrono::milliseconds>
double measure(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now();

    func();

    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<TimeUnit>(end - start);

    return duration.count();
}

#endif //TIMER_H
