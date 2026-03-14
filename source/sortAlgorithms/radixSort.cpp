#include <iostream>
#include <algorithm>
#include <vector>
#include "sort.h"

using namespace std;
struct Bucket {
    int* data;
    int count;
};
void radixSort(vector<int>& arr, long long& comparisons) {
    int size = arr.size();
    if (++comparisons && size <= 0) return; 

    int maxv = arr[0];
    for (int i = 1; ++comparisons && i < size; i++) {
        if (++comparisons && maxv < arr[i]) maxv = arr[i];
    }

    Bucket buckets[10];
    for (int i = 0;++comparisons && i < 10; i++) {
        buckets[i].data = new int[size];
    }

    long long j = 1; 
    while (maxv / j > 0) {
        ++comparisons;
        for (int i = 0;++comparisons && i < 10; i++) {
            buckets[i].count = 0;
        }

        for (int i = 0;++comparisons && i < size; i++) {
            int digit = (arr[i] / j % 10);
            int empty = buckets[digit].count;
            buckets[digit].data[empty] = arr[i];
            buckets[digit].count++;
        }

        int dex = 0;
        for (int i = 0; ++comparisons && i < 10; i++) {
            for (int k = 0; k < buckets[i].count; k++) { 
                arr[dex] = buckets[i].data[k];
                dex++;
            }
        }
        j *= 10;
    }
    for (int i = 0; i < 10; i++) {
        delete[] buckets[i].data;
    }
}
void radixSortTime(vector<int>& arr) {
    int size = arr.size();
    if (size <= 0) return; 

    int maxv = arr[0];
    for (int i = 1;  i < size; i++) {
        if (maxv < arr[i]) maxv = arr[i];
    }

    Bucket buckets[10];
    for (int i = 0; i < 10; i++) {
        buckets[i].data = new int[size];
    }

    long long j = 1; 
    while (maxv / j > 0) {
        for (int i = 0; i < 10; i++) {
            buckets[i].count = 0;
        }

        for (int i = 0; i < size; i++) {
            int digit = (arr[i] / j % 10);
            int empty = buckets[digit].count;
            buckets[digit].data[empty] = arr[i];
            buckets[digit].count++;
        }

        int dex = 0;
        for (int i = 0; i < 10; i++) {
            for (int k = 0; k < buckets[i].count; k++) { 
                arr[dex] = buckets[i].data[k];
                dex++;
            }
        }
        j *= 10;
    }
    for (int i = 0; i < 10; i++) {
        delete[] buckets[i].data;
    }
}