#ifndef SORT_H
#define SORT_H

#include <vector>

void selectionSort(std::vector<int>& array, long long& comparisons);
void selectionSortTime(std::vector<int>& array);
void insertionSort(std::vector<int>& array, long long& comparisons);
void shellSort(std::vector<int>& array, long long& comparisons);
void bubbleSort(std::vector<int>& array, long long& comparisons);
void heapSort(std::vector<int>& array, long long& comparisons);
void mergeSort(std::vector<int>& array, long long& comparisons);
void quickSort(std::vector<int>& array, long long& comparisons);
void radixSort(std::vector<int>& array, long long& comparisons);
void countingSort(std::vector<int>& array, long long& comparisons);
void binaryInsertionSort(std::vector<int>& array, long long& comparisons);
void shakerSort(std::vector<int>& array, long long& comparisons);
void flashSort(std::vector<int>& array, long long& comparisons);

#endif