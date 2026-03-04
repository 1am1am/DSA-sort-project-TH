#include "sort.h"
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int val = array[i];
        int j = i - 1;
        
        while (j >= 0 && array[j] > val) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = val;
    }
}
