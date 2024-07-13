#include "sorting_algorithms.h"
#include <limits>


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
    std::vector<int> L = std::vector<int>(arr.begin()+s, arr.begin()+m+1);
    std::vector<int> R = std::vector<int>(arr.begin()+m+1, arr.begin()+e+1);
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


void quickSort(std::vector<int>& arr, int s, int e) {
    if (e-s+1 <= 1) {
        return;
    }
    int pivot = arr[e];
    int i = s;
    int j = s;
    while (i < e) {
        if (arr[i] <= pivot) {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            j++;
        }
        i++;
    }
    int temp = arr[j];
    arr[j] = pivot;
    arr[e] = temp;
    quickSort(arr, s, j-1);
    quickSort(arr, j+1, e);
}

void bucketSort(std::vector<int>& arr) {
    int max = std::numeric_limits<int>::min();
    int min = std::numeric_limits<int>::max();
    for (int i=0; i<=arr.size()-1; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    if (min < 0) {
        std::vector<int> bucket = std::vector<int>(max-min+1, 0);
        for (int i=0; i<=arr.size()-1; i++) {
            bucket[arr[i]-min] += 1;
        }
        int k = 0;
        for (int i=0; i<=bucket.size()-1; i++) {
            if (bucket[i] > 0) {
                for (int j=0; j < bucket[i]; j++) {
                    arr[k] = i+min;
                    k++;
                }
            }
        }
    }
    else {
        std::vector<int> bucket = std::vector<int>(max+1, 0);
        for (int i=0; i<=arr.size()-1; i++) {
            bucket[arr[i]] += 1;
        }
        int k = 0;
        for (int i=0; i<=bucket.size()-1; i++) {
            if (bucket[i] > 0) {
                for (int j=0; j < bucket[i]; j++) {
                    arr[k] = i;
                    k++;
                }
            }
        }
    }

}