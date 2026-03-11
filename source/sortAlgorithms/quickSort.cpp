#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "sort.h"

using namespace std;

void insertionSortSubmatrix(std::vector<int>& array, int l, int r, long long& comparisons) {
    int n = array.size();
    for (int i = l + 1; ++comparisons && i <= r; ++i) {
        int val = array[i];
        int j = i - 1;
        
        while (++comparisons && j >= 0 && ++comparisons && array[j] > val) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = val;
    }
}

int selectPivot(vector<int>& arr, int l, int r, long long& comparisons) {
    int mid = l + (r - l) / 2;
    if (++comparisons && arr[l] > arr[mid]) std::swap(arr[l], arr[mid]);
    if (++comparisons && arr[mid] > arr[r]) std::swap(arr[mid], arr[r]);
    if (++comparisons && arr[l] > arr[mid]) std::swap(arr[l], arr[mid]);
    return mid;
}

int partition(vector<int>& arr, int l, int r, long long& comparisons) { // lomuto
    int pivotIdx = selectPivot(arr, l, r, comparisons);
    int pivot = arr[pivotIdx];

    std::swap(arr[pivotIdx], arr[r - 1]);
    pivotIdx = r - 1;

    int left = l + 1;
    int right = r - 2;

    while (++comparisons && left <= right) {
        while (++comparisons && arr[left] < pivot) left++;
        while (++comparisons && arr[right] > pivot) right--;

        if (++comparisons && left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    std::swap(arr[pivotIdx], arr[left]);
    pivotIdx = left;
    return pivotIdx;
}

void quickSortArray(vector<int>& array, int l, int r, long long& comparisons) { // lomuto
    if (++comparisons && l < r) {
        if (++comparisons && (r - l) < 10) {
            insertionSortSubmatrix(array, l, r, comparisons);
            return;
        }
        int p = partition(array, l, r, comparisons);
        quickSortArray(array, l, p - 1, comparisons);
        quickSortArray(array, p + 1, r, comparisons);
    }
}
void quickSort(vector<int>& array, long long& comparisons) { // lomuto
    if (++comparisons && !array.empty()) {
        quickSortArray(array, 0, array.size() - 1, comparisons);
    }
}





void insertionSortSubmatrixTime(std::vector<int>& array, int l, int r) {
    int n = array.size();
    for (int i = l + 1; i <= r; ++i) {
        int val = array[i];
        int j = i - 1;
        
        while (j >= 0 && array[j] > val) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = val;
    }
}

int selectPivotTime(vector<int>& arr, int l, int r) {
    int mid = l + (r - l) / 2;
    if (arr[l] > arr[mid]) std::swap(arr[l], arr[mid]);
    if (arr[mid] > arr[r]) std::swap(arr[mid], arr[r]);
    if (arr[l] > arr[mid]) std::swap(arr[l], arr[mid]);
    return mid;
}

int partitionTime(vector<int>& arr, int l, int r) { // lomuto
    int pivotIdx = selectPivotTime(arr, l, r);
    int pivot = arr[pivotIdx];

    std::swap(arr[pivotIdx], arr[r - 1]);
    pivotIdx = r - 1;

    int left = l + 1;
    int right = r - 2;

    while (left <= right) {
        while (arr[left] < pivot) left++;
        while (arr[right] > pivot) right--;

        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    std::swap(arr[pivotIdx], arr[left]);
    pivotIdx = left;
    return pivotIdx;
}

void quickSortArrayTime(vector<int>& array, int l, int r) { // lomuto
    if (l < r) {
        if ((r - l) < 10) {
            insertionSortSubmatrixTime(array, l, r);
            return;
        }
        int p = partitionTime(array, l, r);
        quickSortArrayTime(array, l, p - 1);
        quickSortArrayTime(array, p + 1, r);
    }
}
void quickSortTime(vector<int>& array) { // lomuto
    if (!array.empty()) {
        quickSortArrayTime(array, 0, array.size() - 1);
    }
}