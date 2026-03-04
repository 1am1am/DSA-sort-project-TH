#include <iostream>
#include <vector>
using namespace std;

void Heapify(std::vector<int>&array , int start, int n, long long&comparisons) {
    int leftChild = start *  2 + 1;
    if ( ++comparisons && leftChild >= n) return;
    int largerChild = leftChild;
    int rightChild = start * 2 + 2;
    if (++comparisons && rightChild < n) {
        if (++comparisons && array[rightChild] > array[leftChild]) {
            largerChild = rightChild;
        }
    }

    if (++comparisons && array[start] < array[largerChild] ) {
        std::swap(array[start], array[largerChild]);
        Heapify(array,largerChild,n,comparisons);
    }
}


void heapSort(std::vector<int>&array, long long &comparisons) {
    for (int i = (array.size()-1)/2; ++comparisons && i >= 0 ; i--) {
        Heapify(array,i,array.size(),comparisons);
    }
    std::swap(array[0], array[array.size()-1]);
    int HeapSize = array.size()-1;
    while (++comparisons && HeapSize > 1) {
        Heapify(array,0,HeapSize, comparisons);
        HeapSize--;
        std::swap(array[0], array[HeapSize]);
    }
}