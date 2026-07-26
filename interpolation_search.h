// ============================================================
// interpolation_search.h - Interpolation Search Algorithm Header
// ITS60504 Data Structures and Algorithms
// ============================================================
// TEAMMATE STUB: This file needs to be implemented by the
// team member assigned to Interpolation Search.
// ============================================================

#ifndef INTERPOLATION_SEARCH_H
#define INTERPOLATION_SEARCH_H

#include "record.h"
#include <vector>

// -------------------------------------------------------
// interpolationSearch
// -------------------------------------------------------
// Searches for a target value in a SORTED vector of Records
// using the Interpolation Search algorithm.
//
// PREREQUISITE: The vector MUST be sorted in ascending order
//               by the 'value' field before calling this.
//               Works best with uniformly distributed data.
//
// Parameters:
//   records - const reference to the sorted vector
//   target  - the integer value to search for
//
// Returns:
//   Index of the record if found, -1 if not found
//
// Time Complexity:
//   Best Case:    O(1)
//   Average Case: O(log log n) - for uniformly distributed data
//   Worst Case:   O(n) - for non-uniform distribution
// -------------------------------------------------------
int interpolationSearch(const std::vector<Record>& records, int target);

#endif // INTERPOLATION_SEARCH_H
