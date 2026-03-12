#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "sort.h"

using namespace std;

void shakerSort(vector<int>& A, long long& comparisions){
    int l = 0, r = A.size() - 1, pos = A.size() - 1;
    while(++comparisions && l < r){
        for(int i = l + 1; ++comparisions && i <= r; ++i){
            if(++comparisions && A[i] < A[i - 1]){
                swap(A[i], A[i - 1]);
                pos = i - 1;
            }
        }
        r = pos;
        for(int i = r - 1; ++comparisions && i >= l ; --i){
            if( ++comparisions && A[i] > A[i + 1]){
                swap(A[i], A[i + 1]);
                pos = i + 1;
            }
        }
        l = pos;
    }
}

void shakerSortTime(vector<int>& A){
    int l = 0, r = A.size() - 1, pos = A.size() - 1;
    while(l < r){
        for(int i = l + 1; i <= r; ++i){
            if(A[i] < A[i - 1]){
                swap(A[i], A[i - 1]);
                pos = i - 1;
            }
        }
        r = pos;
        for(int i = r - 1; i >= l ; --i){
            if(A[i] > A[i + 1]){
                swap(A[i], A[i + 1]);
                pos = i + 1;
            }
        }
        l = pos;
    }
}