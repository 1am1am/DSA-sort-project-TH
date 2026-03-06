#include <iostream>
#include <vector>
#include "sort.h"
void bubbleSort(std::vector<int>& array, long long& comparisons) {
    for (int i = 0; ++comparisons && i < array.size(); i++) {
        for (int j = array.size() - 1; ++comparisons && j > i; j--) {
            if (++comparisons && array[j - 1] > array[j]) {
                std::swap(array[j - 1], array[j]);
            }
        }
    }
}
