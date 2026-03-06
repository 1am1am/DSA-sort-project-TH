#include "sort.h"
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& array, long long& comparisons) {
    int n = array.size();
    for (int i = 1; ++comparisons && i < n; ++i) {
        int val = array[i];
        int j = i - 1;
        
        while (++comparisons && j >= 0 && ++comparisons && array[j] > val) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = val;
    }
}
