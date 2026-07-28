#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include "record.h"

// Sorts records in ascending order by value, using Selection Sort
void selectionSort(std::vector<Record>& records);

// Sorts records in ascending order by value, using Quick Sort
void quickSort(std::vector<Record>& records, int low, int high);

// Sorts records in ascending order by value, using Merge Sort
void mergeSort(std::vector<Record>& records, int left, int right);

#endif