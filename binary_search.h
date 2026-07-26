// ============================================================
// binary_search.h - Binary Search Algorithm Header
// ITS60504 Data Structures and Algorithms
// ============================================================
// TEAMMATE STUB: This file needs to be implemented by the
// team member assigned to Binary Search.
// ============================================================

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include "record.h"
#include <vector>

// -------------------------------------------------------
// binarySearch
// -------------------------------------------------------
// Searches for a target value in a SORTED vector of Records
// using the Binary Search algorithm.
//
// PREREQUISITE: The vector MUST be sorted in ascending order
//               by the 'value' field before calling this.
//
// Parameters:
//   records - const reference to the sorted vector
//   target  - the integer value to search for
//
// Returns:
//   Index of the record if found, -1 if not found
//
// Time Complexity:
//   Best Case:    O(1) - target is at the midpoint
//   Average Case: O(log n)
//   Worst Case:   O(log n)
// -------------------------------------------------------
int binarySearch(const std::vector<Record>& records, int target);

#endif // BINARY_SEARCH_H
