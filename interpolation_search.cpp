// ============================================================
// interpolation_search.cpp - Interpolation Search Implementation
// ITS60504 Data Structures and Algorithms
// ============================================================
// TODO: This file must be implemented by the team member
//       assigned to Interpolation Search.
//
// Instructions for teammate:
//   1. Implement Interpolation Search algorithm
//   2. Search based on the 'value' field of Record
//   3. Return the index if found, -1 if not found
//   4. Do NOT modify the function signature in interpolation_search.h
//   5. IMPORTANT: Data must be sorted before using this search
//   6. Use the interpolation formula to estimate position:
//      pos = low + ((target - arr[low]) * (high - low)) /
//                   (arr[high] - arr[low])
// ============================================================

#include "interpolation_search.h"

// TODO: Implement Interpolation Search algorithm here
int interpolationSearch(const std::vector<Record>& records, int target) {
    // ----- PLACEHOLDER: Replace with actual implementation -----
    // Example structure:
    //
    // int low = 0, high = records.size() - 1;
    // while (low <= high && target >= records[low].value
    //        && target <= records[high].value) {
    //     if (low == high) {
    //         if (records[low].value == target) return low;
    //         return -1;
    //     }
    //     int pos = low + ((double)(target - records[low].value)
    //               * (high - low))
    //               / (records[high].value - records[low].value);
    //     if (records[pos].value == target) return pos;
    //     if (records[pos].value < target) low = pos + 1;
    //     else high = pos - 1;
    // }
    // return -1;
    // -----------------------------------------------------------

    return -1;  // Placeholder return
}
