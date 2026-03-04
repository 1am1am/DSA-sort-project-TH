#include <iostream>
#include <vector>
#include "sort.h"
void shellSort(std::vector<int>& array,  long long& comparisons) {
    for (int i = (array.size())/2; ++comparisons && i > 0 ; i/=2) {
        for (int j = i; ++comparisons && j < array.size();j++) {
            int tmp = array[j];
            int k = j - i;
            while ( ++ comparisons && k >= 0 && ++comparisons && array[k] > tmp ) {
                array[k+i] = array[k];
                k = k - i;
            }
            array[k+i] = tmp;

        }
    }
}