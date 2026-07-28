// ============================================================
// timer.h - Execution Time Measurement Utility
// ITS60504 Data Structures and Algorithms
// ============================================================
// Provides a simple Timer class using C++ <chrono> library
// to measure the actual execution time of algorithms in
// milliseconds, as required by the assignment.
// ============================================================

#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point startTime;
    std::chrono::high_resolution_clock::time_point endTime;

public:
    // Start the timer
    void start() {
        startTime = std::chrono::high_resolution_clock::now();
    }

    // Stop the timer
    void stop() {
        endTime = std::chrono::high_resolution_clock::now();
    }

    // Get elapsed time in milliseconds (with microsecond precision)
    double getElapsedMilliseconds() const {
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
            endTime - startTime
        );
        return duration.count() / 1000.0;
    }
};

#endif // TIMER_H
