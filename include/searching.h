#ifndef SEARCHING_H
#define SEARCHING_H

#include <vector>
#include "record.h"

// it returns index of target if found, else -1. Requires sorted data.
int binarySearch(const std::vector<Record>& records, int target);

// it returns index of target if found, else -1. Requires sorted and uniformly distributed data.
int interpolationSearch(const std::vector<Record>& records, int target);

#endif