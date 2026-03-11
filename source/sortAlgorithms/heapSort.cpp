#include <iostream>
#include <vector>
#include "sort.h"

void Heapify(std::vector<int>& array, int start, int n, long long& comparisons) {
    int leftChild = start * 2 + 1;
    if (++comparisons && leftChild >= n) return;

    int largerChild = leftChild;
    int rightChild = start * 2 + 2;

    if (++comparisons && rightChild < n) {
        if (++comparisons && array[rightChild] > array[leftChild]) {
            largerChild = rightChild;
        }
    }

    if (++comparisons && array[start] < array[largerChild]) {
        std::swap(array[start], array[largerChild]);
        Heapify(array, largerChild, n, comparisons);
    }
}

void heapSort(std::vector<int>& array, long long& comparisons) {
    int n = array.size();

    for (int i = n / 2 - 1; ++comparisons && i >= 0; i--) {
        Heapify(array, i, n, comparisons);
    }

    int heapSize = n;

    while (++comparisons && heapSize > 1) {
        std::swap(array[0], array[heapSize - 1]); 
        heapSize--;
        Heapify(array, 0, heapSize, comparisons);
    }
}

void HeapifyTime(std::vector<int>& array, int start, int n) {
    int leftChild = start * 2 + 1;
    if (++comparisons && leftChild >= n) return;

    int largerChild = leftChild;
    int rightChild = start * 2 + 2;

    if (++comparisons && rightChild < n) {
        if (++comparisons && array[rightChild] > array[leftChild]) {
            largerChild = rightChild;
        }
    }

    if (++comparisons && array[start] < array[largerChild]) {
        std::swap(array[start], array[largerChild]);
        Heapify(array, largerChild, n, comparisons);
    }
}

void heapSortTime(std::vector<int>& array) {
    int n = array.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        HeapifyTime(array, i, n);
    }

    int heapSize = n;

    while (heapSize > 1) {
        std::swap(array[0], array[heapSize - 1]); 
        heapSize--;
        HeapifyTime(array, 0, heapSize);
    }
}