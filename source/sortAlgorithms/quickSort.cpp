#include <iostream>
#include <algorithm>
#include <vector>
#include "sort.h"

using namespace std;

int partition(vector<int>& arr, int l, int r, long long& comparisons) { 
    int mid = l + (r - l) / 2;
    swap(arr[mid], arr[r]); 

    int pivot = arr[r];
    int j = l - 1;
    for (int i = l; ++comparisons && i < r; i++) {
        if (++comparisons && arr[i] <= pivot) {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    j++;
    swap(arr[j], arr[r]);
    return j;
}

void quickSortArray(vector<int>& array, int l, int r, long long& comparisons) { 
    if (++comparisons && l < r) {
        int p = partition(array, l, r, comparisons);
        quickSortArray(array, l, p - 1, comparisons);
        quickSortArray(array, p + 1, r, comparisons);
    }
}

void quickSort(vector<int>& array, long long& comparisons) { 
    comparisons = 0; 
    if (!array.empty()) {
        quickSortArray(array, 0, array.size() - 1, comparisons);
    }
}


int partitionTime(vector<int>& arr, int l, int r) { 
    int mid = l + (r - l) / 2;
    swap(arr[mid], arr[r]); 

    int pivot = arr[r];
    int j = l - 1;
    for (int i = l; i < r; i++) {
        if (arr[i] <= pivot) {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    j++;
    swap(arr[j], arr[r]);
    return j;
}

void quickSortArrayTime(vector<int>& array, int l, int r) { 
    if (l < r) {
        int p = partitionTime(array, l, r);
        quickSortArrayTime(array, l, p - 1);
        quickSortArrayTime(array, p + 1, r);
    }
}

void quickSortTime(vector<int>& array) { 
    if (!array.empty()) {
        quickSortArrayTime(array, 0, array.size() - 1);
    }
}