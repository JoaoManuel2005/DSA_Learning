#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <vector>

int recursive_binarySearch(std::vector<int>& arr, int L, int R, int value);
int binarySearch(std::vector<int>& arr, int value);
bool searchMatrix2(std::vector<std::vector<int>>& matrix, int target);
bool searchMatrix(std::vector<std::vector<int>>& matrix, int target);

#endif // SEARCH_ALGORITHMS_H