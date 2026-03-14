#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;
void bubbleSort(std::vector<int>& array, long long& comparisons) {
    int n = array.size();
    for(int i = 0; ++ comparisons && i < n; ++i) {
        for (int j = 0 ; ++ comparisons && j < n - i; j++ ) {
            if (++ comparisons && array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

void bubbleSortTime(std::vector<int>& array) {
    int n = array.size();
    for(int i = 0; i < n; ++i) {
        for (int j = 0 ; j < n - i; j++ ) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}