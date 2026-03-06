#include <iostream>
#include <vector>
#include "sort.h"
void bubbleSort(std::vector<int>& array, long long& comparisons) {
    for (int i = 0 ; ++comparisons && i < array.size() - 1; i++) {
        for (int j = 0 ; ++comparisons && j  < array.size() - i - 1 ; j++) {
            if (++comparisons && array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}
