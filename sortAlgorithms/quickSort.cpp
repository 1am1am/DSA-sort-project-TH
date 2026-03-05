#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "sort.h"

using namespace std;

int partition(vector<int>& arr, int l, int r, long long& comparisons) { // lomuto
    int pivot = arr[r];
    int j = l - 1;
    for (int i = l; i < r; i++) {
        comparisons++; 
        if (arr[i] <= pivot) {
            j++;
            swap(arr[j], arr[i]);
        }
    }
    j++;
    swap(arr[j], arr[r]);
    return j;
}

void quickSortArray(vector<int>& array, int l, int r, long long& comparisons) { // lomuto
    if (l < r) {
        int p = partition(array, l, r, comparisons);
        quickSortArray(array, l, p - 1, comparisons);
        quickSortArray(array, p + 1, r, comparisons);
    }
}
void quickSort(vector<int>& array, long long& comparisons) { // lomuto
    comparisons = 0; 

    if (!array.empty()) {
        quickSortArray(array, 0, array.size() - 1, comparisons);
    }
}
