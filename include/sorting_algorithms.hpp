#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>

void insertionSort(std::vector<int>& arr);
void merge(std::vector<int>&arr, int s, int m, int e);
void mergeSort(std::vector<int>& arr, int s, int e);
void quickSort(std::vector<int>& arr, int s, int e);
void bucketSort(std::vector<int>& arr);

#endif // SORTING_ALGORITHMS_H