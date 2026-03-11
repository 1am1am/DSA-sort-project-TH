#include "sort.h"
#include <iostream>
#include <vector>

void flashSort(std::vector<int>& array, long long& comparisons) {
    int n = array.size();
    if (++comparisons && n <= 1) return;

    int m = 0.45 * n;
    if (++comparisons && m < 1) m = 1;
    int* L = new int[m]{0};

    int minVal = array[0];
    int maxIndex = 0;

    for (int i = 1; ++comparisons && i < n; ++i) {
        if (++comparisons && array[i] < minVal) minVal = array[i];
        if (++comparisons && array[i] > array[maxIndex]) maxIndex = i;
    }

    if (++comparisons && array[maxIndex] == minVal) {
        delete[] L;
        return;
    }

    double c1 = (double)(m - 1) / (array[maxIndex] - minVal);

    for (int i = 0; ++comparisons && i < n; ++i) {
        int k = (int)(c1 * (array[i] - minVal));
        L[k]++;
    }

    for (int i = 1; ++comparisons && i < m; ++i) {
        L[i] += L[i - 1];
    }

    std::swap(array[0], array[maxIndex]); 
    int move = 0;
    int j = 0;
    int k = m - 1;

    while (++comparisons && move < n - 1) {
        while (++comparisons && j >= L[k]) {
            j++;
            k = (int)(c1 * (array[j] - minVal));
        }
        
        int flash = array[j];
        while (++comparisons && j != L[k]) {
            k = (int)(c1 * (flash - minVal));
            int pos = --L[k];
            std::swap(flash, array[pos]);
            move++;
        }
    }

    delete[] L;
    L = nullptr;
    insertionSort(array, comparisons);
}

void flashSort(std::vector<int>& array) {
    int n = array.size();
    if (n <= 1) return;

    int m = 0.45 * n;
    if (m < 1) m = 1;
    int* L = new int[m]{0};

    int minVal = array[0];
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (array[i] < minVal) minVal = array[i];
        if (array[i] > array[maxIndex]) maxIndex = i;
    }

    if (array[maxIndex] == minVal) {
        delete[] L;
        return;
    }

    double c1 = (double)(m - 1) / (array[maxIndex] - minVal);

    for (int i = 0; i < n; ++i) {
        int k = (int)(c1 * (array[i] - minVal));
        L[k]++;
    }

    for (int i = 1; i < m; ++i) {
        L[i] += L[i - 1];
    }

    std::swap(array[0], array[maxIndex]); 
    int move = 0;
    int j = 0;
    int k = m - 1;

    while (move < n - 1) {
        while (j >= L[k]) {
            j++;
            k = (int)(c1 * (array[j] - minVal));
        }
        
        int flash = array[j];
        while (j != L[k]) {
            k = (int)(c1 * (flash - minVal));
            int pos = --L[k];
            std::swap(flash, array[pos]);
            move++;
        }
    }

    delete[] L;
    L = nullptr;
    insertionSortTime(array);
}