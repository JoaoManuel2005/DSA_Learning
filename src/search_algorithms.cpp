#include "search_algorithms.h"

int recursive_binarySearch(std::vector<int>& arr, int L, int R, int value) {
    if (L > R) {
        return -1;
    }
    int mid = (L+R) / 2;
    if (arr[mid] == value) {
        return mid;
    }
    else if (arr[mid] > value) {
        return recursive_binarySearch(arr, 0, mid-1, value);
    }
    else {
        return recursive_binarySearch(arr, mid+1, arr.size()-1, value);
    }
}

int binarySearch(std::vector<int>& arr, int value) {
    int L = 0;
    int R = arr.size()-1;
    while (L <= R) {
        int mid = (L+R) / 2;
        if (arr[mid] == value) {
            return mid;
        }
        else if (arr[mid] > value) {
            R = mid-1;
        }
        else {
            L = mid+1;
        }
    }
    return -1;
}