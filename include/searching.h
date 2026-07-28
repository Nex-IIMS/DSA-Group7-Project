#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include "record.h"

// Returns index of target if found, else -1. Requires sorted data.
int binarySearch(const std::vector<Record>& records, int target);

// Returns index of target if found, else -1. Requires sorted, uniformly distributed data.
int interpolationSearch(const std::vector<Record>& records, int target);

#endif