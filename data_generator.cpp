// ============================================================
// data_generator.cpp - Random Data Generation Implementation
// ITS60504 Data Structures and Algorithms
// ============================================================
// Implements functions to automatically generate and load
// dummy records populated with random integer values.
// Uses C++ <random> library for high-quality random numbers.
// ============================================================

#include "data_generator.h"
#include <random>
#include <ctime>

// -------------------------------------------------------
// generateRecords (default range: 1 to 10000)
// -------------------------------------------------------
// Generates 'count' Record objects, each with:
//   - A sequential ID (1, 2, 3, ...)
//   - A random integer value between 1 and 10000
//
// Uses Mersenne Twister (mt19937) for uniform distribution.
// -------------------------------------------------------
std::vector<Record> generateRecords(int count) {
    return generateRecords(count, 1, 10000);
}

// -------------------------------------------------------
// generateRecords (custom range)
// -------------------------------------------------------
// Overloaded version that allows specifying the value range.
// Useful for scalability testing with different distributions.
// -------------------------------------------------------
std::vector<Record> generateRecords(int count, int minValue, int maxValue) {
    std::vector<Record> records;
    records.reserve(count);  // Pre-allocate memory for efficiency

    // Seed the random number generator with current time
    std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
    std::uniform_int_distribution<int> dist(minValue, maxValue);

    for (int i = 0; i < count; i++) {
        Record r;
        r.id = i + 1;       // Sequential ID starting from 1
        r.value = dist(rng); // Random value in [minValue, maxValue]
        records.push_back(r);
    }

    return records;
}
