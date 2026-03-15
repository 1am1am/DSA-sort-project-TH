#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

void binaryInsertionSort(vector<int>& A, long long& comparisions){
    for(int i = 1; ++comparisions && i < A.size(); ++i){
        int value = A[i];
        int l = 0, r = i - 1, pos = i;
        while (++comparisions && l <= r){
            int m = l + ((r - l) >> 1);
            if (++comparisions && A[m] >= value){
                r = m - 1;
                pos = m;
            }
            else l = m + 1;
        }
        for(int j = i; ++comparisions && j > pos; --j) A[j] = A[j - 1];
        A[pos] = value;
    }
}

void binaryInsertionSortTime(vector<int>& A){
    for(int i = 1; i < A.size(); ++i){
        int value = A[i];
        int l = 0, r = i - 1, pos = i;
        while (l <= r){
            int m = l + ((r - l) >> 1);
            if (A[m] >= value){
                r = m - 1;
                pos = m;
            }
            else l = m + 1;
        }
        for(int j = i; j > pos; --j) A[j] = A[j - 1];
        A[pos] = value;
    }
}