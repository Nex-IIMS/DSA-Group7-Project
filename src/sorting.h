#ifndef SORTING_H
#define SORTING_H

#include <vector>

namespace sorting {
void selectionSort(std::vector<int>& arr);
void quickSort(std::vector<int>& arr, int low, int high);
void mergeSort(std::vector<int>& arr, int left, int right);
}

#endif
