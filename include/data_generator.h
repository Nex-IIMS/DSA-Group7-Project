// ============================================================
// data_generator.h - Random Data Generation Header
// ITS60504 Data Structures and Algorithms
// ============================================================

#ifndef DATA_GENERATOR_H
#define DATA_GENERATOR_H

#include "record.h"
#include <vector>

// Generates 'count' records with sequential IDs and random integer values.
// Values range from 1 to 10000 by default.
std::vector<Record> generateRecords(int count);

// Generates records with values in a specific range (useful for testing)
std::vector<Record> generateRecords(int count, int minValue, int maxValue);

#endif // DATA_GENERATOR_H
