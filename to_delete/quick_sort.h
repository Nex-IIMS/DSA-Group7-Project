// ============================================================
// quick_sort.h - Quick Sort Algorithm Header
// ITS60504 Data Structures and Algorithms
// ============================================================
// TEAMMATE STUB: This file needs to be implemented by the
// team member assigned to Quick Sort.
// ============================================================

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "record.h"
#include <vector>

// -------------------------------------------------------
// quickSort
// -------------------------------------------------------
// Sorts a vector of Records in ascending order by value
// using the Quick Sort algorithm (divide and conquer).
//
// Parameters:
//   records - reference to the vector to sort
//   low     - starting index of the partition
//   high    - ending index of the partition
//
// Initial call: quickSort(records, 0, records.size() - 1)
//
// Time Complexity:
//   Best Case:    O(n log n)
//   Average Case: O(n log n)
//   Worst Case:   O(n^2) - when pivot is always min or max
// Space Complexity: O(log n) - recursive stack
// -------------------------------------------------------
void quickSort(std::vector<Record>& records, int low, int high);

#endif // QUICK_SORT_H
