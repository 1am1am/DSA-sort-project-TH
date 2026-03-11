#ifndef SORT_H
#define SORT_H

#include <vector>

void selectionSort(std::vector<int>& array, long long& comparisons);
void selectionSortTime(std::vector<int>& array);

void insertionSort(std::vector<int>& array, long long& comparisons);
void insertionSortTime(std::vector<int>& array);

void shellSort(std::vector<int>& array, long long& comparisons);
void shellSortTime(std::vector<int>& array);

void bubbleSort(std::vector<int>& array, long long& comparisons);
void bubbleSortTime(std::vector<int>& array);

void heapSort(std::vector<int>& array, long long& comparisons);
void heapSortTime(std::vector<int>& array);

void mergeSort(std::vector<int>& array, long long& comparisons);
void mergeSortTime(std::vector<int>& array);

void quickSort(std::vector<int>& array, long long& comparisons);
void quickSortTime(std::vector<int>& array);

void radixSort(std::vector<int>& array, long long& comparisons);
void radixSortTime(std::vector<int>& array);

void countingSort(std::vector<int>& array, long long& comparisons);
void countingSortTime(std::vector<int>& array);

void binaryInsertionSort(std::vector<int>& array, long long& comparisons);
void binaryInsertionSortTime(std::vector<int>& array);

void shakerSort(std::vector<int>& array, long long& comparisons);
void shakerSortTime(std::vector<int>& array);

void flashSort(std::vector<int>& array, long long& comparisons);
void flashSortTime(std::vector<int>& array);

#endif