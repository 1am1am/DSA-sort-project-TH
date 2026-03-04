#include "sort.h"
#include <iostream>
#include <vector>

void flashSort(std::vector<int>& array, long long& comparisons) {
    int n = array.size();
    if (n <= 1) return;
    int m = 0.45 * n;
    int* L = new int[m]{0};
    int maxVal = array[0], minVal = array[0];

    for (int i = 1; i < n; ++i) {
        maxVal = std::max(maxVal, array[i]);
        minVal = std::min(minVal, array[i]);
    }

    for (int i = 0; i < n; ++i) {
        int k = 1.0 * (m - 1) * (array[i] - minVal) / (maxVal - minVal);
        ++L[k];
    }

    for (int i = 1; i < m; ++i) {
        L[i] += L[i - 1];
    }
    
    int hold = array[0];
    int move = 0;
    int flash = 0;
    int k = 0;
    int t = 0;
    int j = 0;

    while (move < n - 1) {
        while (j > (L[k] - 1)) {
            ++j;
            k = 1.0 * (m - 1) * (array[j] - minVal) / (maxVal - minVal);
        }

        flash = array[j];
        while (j != L[k]) {
            k = 1.0 * (m - 1) * (array[j] - minVal) / (maxVal - minVal);
            hold = array[t=--L[k]];
            array[t] = hold;
            flash = hold;
            ++move;

        }
    }

    insertionSort(array, comparisons);

    delete[] L;
    L = nullptr;
}