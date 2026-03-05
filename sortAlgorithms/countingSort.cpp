#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;

void countingSort(vector<int>& A, long long& comparisions){
    int maxv = 0;
    for(int i = 0; i < A.size(); ++i) maxv = max(maxv, A[i]);
    int* Count = new int[maxv + 5];
    for(int i = 0; i <= maxv; ++i) Count[i] = 0;
    for(int i = 0; i < A.size(); ++i) ++Count[A[i]];
    for(int i = 1; i <= maxv; ++i) Count[i] += Count[i - 1];
    int* B = new int [A.size() + 5];
    for(int i = A.size() - 1; i >= 0; --i) B[Count[A[i]] - 1] = A[i], --Count[A[i]];
    for(int i = 0; i < A.size(); ++i) A[i] = B[i];
    delete[]Count;
    delete[]B;
}