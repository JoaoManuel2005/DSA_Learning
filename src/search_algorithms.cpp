#include "search_algorithms.hpp"

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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int row_length = matrix[0].size()-1;
    std::cout << row_length << std::endl;
    while (row < matrix.size() && row_length >= 0) {
        if (matrix[row][row_length] == target) {
            return true;
        }
        else if (matrix[row][row_length] > target) {
            row_length--;
        }
        else {
            row++;
        }
    }
    return false;
}

//needs to be fixed
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        vector<int> L = {0, 0};
        vector<int> R = {static_cast<int>(matrix.size()-1), static_cast<int>(matrix[0].size()-1)}; 
        while (L[0] <= R[0] && L[1] <= R[1]) {
            vector<int> mid = {(L[0] + R[0])/2, (L[1] + R[1])/2};
            if (matrix[mid[0]][mid[1]] == target) {
                return true;
            }
            else if (matrix[mid[0]][mid[1]] > target) {
                R = mid;
                if (R[1] == 0) {
//                    if (R[0] == 0) {
  //                      return false;
    //                }
                    R[0]--;
                    R[1] = matrix[0].size() - 1;
                } 
                else {
                    R[1]--;
                }
            }
            else {
                L = mid;
                if (L[1] == matrix[0].size() - 1) {
        //            if (L[0] == matrix.size() - 1) {
          //              return false;
            //        }
                    L[0]++;
                    L[1] = 0;
                } 
                else {
                    L[1]++;
                }
            }
        }
        if (binarySearch(matrix[0], target)) {
            return true;
        }
        else {
            return false;
        }
    }