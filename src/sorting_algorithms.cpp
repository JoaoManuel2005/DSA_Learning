#include "sorting_algorithms.h"


void insertionSort(std::vector<int>& arr) {
    for (int i=1; i<arr.size(); i++) {
        int j = i-1;
        while (j>=0 && arr[j+1] < arr[j]) {
            int temp = arr[j+1]; 
            arr[j+1] = arr[j];
            arr[j] = temp; 
            j--; 
        }
    }
}

void merge(std::vector<int>& arr, int s, int m, int e) {
    std::vector<int> L = std::vector<int>(arr.begin()+s, arr.begin()+m);
    std::vector<int> R = std::vector<int>(arr.begin()+m+1, arr.begin()+e);
    int i = 0;
    int j = 0;
    int k = s;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < L.size()) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < R.size()) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& arr, int s, int e) {
    if (e-s+1 <= 1) {
        return;
    }
    int m = (s+e) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, m , e);
}

