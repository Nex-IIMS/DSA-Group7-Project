// ============================================================
// selection_sort.cpp - Selection Sort Algorithm Implementation
// ITS60504 Data Structures and Algorithms
// ============================================================
// Implements the Selection Sort algorithm to arrange records
// in ascending order based on their 'value' field.
//
// Algorithm Logic:
//   1. Divide the array into sorted (left) and unsorted (right) portions.
//   2. Find the minimum element in the unsorted portion.
//   3. Swap it with the first element of the unsorted portion.
//   4. Move the boundary one position to the right.
//   5. Repeat until the entire array is sorted.
// ============================================================

#include "selection_sort.h"
#include <algorithm>  // For std::swap

void selectionSort(std::vector<Record>& records) {
    int n = records.size();

    // Traverse through each position in the array
    for (int i = 0; i < n - 1; i++) {
        // Assume the current position holds the minimum
        int minIndex = i;

        // Search the unsorted portion for a smaller element
        for (int j = i + 1; j < n; j++) {
            if (records[j].value < records[minIndex].value) {
                minIndex = j;  // Update minimum index
            }
        }

        // Swap only if a smaller element was found
        if (minIndex != i) {
            std::swap(records[i], records[minIndex]);
        }
    }
}
