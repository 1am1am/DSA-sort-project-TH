#include <iostream>
#include <algorithm>
#include <vector>
#include "sort.h"

using namespace std;

void radixSort(vector<int>& array, long long& comparisons) {
    if (array.empty()) return;

    int size = array.size();
    
    int maxv = array[0];
    for (int i = 1; ++comparisons && i < size; i++) {
        if (maxv < array[i]) maxv = array[i];
    }

    long long j = 1;
    while (maxv / j > 0) {
        ++comparisons;
        
        int* Count = new int[10];
        for (int i = 0; i < 10; ++i) Count[i] = 0;

        for (int i = 0; ++comparisons && i < size; ++i) {
            int digit = (array[i] / j) % 10;
            ++Count[digit];
        }

        for (int i = 1; i < 10; ++i) {
            Count[i] += Count[i - 1];
        }

        int* B = new int[size + 5];
        
        for (int i = size - 1; i >= 0; --i) {
            int digit = (array[i] / j) % 10;
            B[Count[digit] - 1] = array[i];
            --Count[digit];
        }

        for (int i = 0; ++comparisons && i < size; ++i) {
            array[i] = B[i];
        }

        delete[] Count;
        delete[] B;
        

        j *= 10;
    }
}