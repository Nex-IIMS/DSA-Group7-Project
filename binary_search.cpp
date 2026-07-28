// ============================================================
// binary_search.cpp - Binary Search Algorithm Implementation
// ITS60504 Data Structures and Algorithms
// ============================================================
// TODO: This file must be implemented by the team member
//       assigned to Binary Search.
//
// Instructions for teammate:
//   1. Implement iterative or recursive Binary Search
//   2. Search based on the 'value' field of Record
//   3. Return the index if found, -1 if not found
//   4. Do NOT modify the function signature in binary_search.h
//   5. IMPORTANT: Data must be sorted before using this search
// ============================================================

#include "binary_search.h"

int binarySearch(const std::vector<Record>& records, int target)
{
    int low = 0;
    int high = records.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (records[mid].value == target)
        {
            return mid;
        }

        else if (records[mid].value < target)
        {
            low = mid + 1;
        }

        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
