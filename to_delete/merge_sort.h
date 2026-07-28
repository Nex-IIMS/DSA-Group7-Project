// ============================================================
// merge_sort.h - Merge Sort Algorithm Header
// ITS60504 Data Structures and Algorithms
// ============================================================
// TEAMMATE STUB: This file needs to be implemented by the
// team member assigned to Merge Sort.
// ============================================================

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "record.h"
#include <vector>

// -------------------------------------------------------
// mergeSort
// -------------------------------------------------------
// Sorts a vector of Records in ascending order by value
// using the Merge Sort algorithm (divide and conquer).
//
// Parameters:
//   records - reference to the vector to sort
//   left    - starting index
//   right   - ending index
//
// Initial call: mergeSort(records, 0, records.size() - 1)
//
// Time Complexity:
//   Best Case:    O(n log n)
//   Average Case: O(n log n)
//   Worst Case:   O(n log n)
// Space Complexity: O(n) - temporary arrays for merging
// -------------------------------------------------------
void mergeSort(std::vector<Record>& records, int left, int right);

#endif // MERGE_SORT_H
