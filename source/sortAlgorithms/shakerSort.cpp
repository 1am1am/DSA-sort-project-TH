#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "sort.h"

using namespace std;

void shakerSort(vector<int>& A, long long& comparisions){
    bool swapped = 1;
    while(++comparisions && swapped){
        swapped = 0;
        for(int i = 0; ++comparisions && i < (int)A.size() - 1; ++i){
            if(++comparisions && A[i] > A[i + 1]){
                swap(A[i], A[i + 1]);
                swapped = 1;
            }
        }
        if(++comparisions && !swapped) break;

        swapped = 0;
        for(int i = (int)A.size() - 2; ++comparisions && i >= 0 ; --i){
            if( ++comparisions && A[i] > A[i + 1]){
                swap(A[i], A[i + 1]);
                swapped = 1;
            }
        }
    }
}

void shakerSortTime(vector<int>& A){
   bool swapped = 1;
    while(swapped){
        swapped = 0;
        for(int i = 0; i < A.size() - 1; ++i){
            if(A[i] > A[i + 1]){
                swap(A[i], A[i + 1]);
                swapped = 1;
            }
        }
        if(!swapped) break;

        swapped = 0;
        for(int i = A.size() - 2; i >= 0 ; --i){
            if(A[i] > A[i + 1]){
                swap(A[i], A[i + 1]);
                swapped = 1;
            }
        }
    }
}