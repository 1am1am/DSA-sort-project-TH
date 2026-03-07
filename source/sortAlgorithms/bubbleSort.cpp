#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;
void bubbleSort(std::vector<int>& array, long long& comparisons) {
    bool unsorted = true;
    int pas = 0 ; 
    int n = array.size();
    while (unsorted) {
        unsorted = false;
        pas++;
        for (int i = 0 ; ++ comparisons && i < n - pas; i++ ) {
            if (++ comparisons && array[i] > array[i+1]) {
                swap(array[i], array[i+1]);
                unsorted = true;    
            }
        }
    }
}