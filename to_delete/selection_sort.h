// ============================================================
// selection_sort.h - Selection Sort Algorithm Header
// ITS60504 Data Structures and Algorithms
// ============================================================

#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include "record.h"
#include <vector>

// -------------------------------------------------------
// selectionSort
// -------------------------------------------------------
// Sorts a vector of Records in ascending order by value
// using the Selection Sort algorithm.
//
// Time Complexity:
//   Best Case:    O(n^2) - still scans all remaining elements
//   Average Case: O(n^2)
//   Worst Case:   O(n^2)
// Space Complexity: O(1) - in-place sorting
// -------------------------------------------------------
void selectionSort(std::vector<Record>& records);

#endif // SELECTION_SORT_H
