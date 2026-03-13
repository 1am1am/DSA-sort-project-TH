#include "sort.h"
#include <iostream>
#include <vector>

const int MAX_SIZE = 1e6;
long long countCompare = 0;
std::vector<int> tempArr(MAX_SIZE);

void merge(std::vector<int>& array, int left, int mid, int right) {
    int first1 = left, last1 = mid;
    int first2 = mid + 1, last2 = right;

    int index = left;
    while ((++countCompare && first1 <= last1) && (++countCompare && first2 <= last2)) {
        if (++countCompare && array[first1] < array[first2]) tempArr[index++] = array[first1++];
        else tempArr[index++] = array[first2++];
    }

    while (++countCompare && first1 <= last1) tempArr[index++] = array[first1++];
    while (++countCompare && first2 <= last2) tempArr[index++] = array[first2++];

    for (int i = left; ++countCompare && i <= right; ++i) {
        array[i] = tempArr[i];
    }
}

void mergeArray(std::vector<int>& array, int left, int right) {
    if (++countCompare && left >= right) return;

    int mid = (left + right) / 2;

    mergeArray(array, left, mid);
    mergeArray(array, mid + 1, right);

    merge(array, left, mid, right);
}

void mergeSort(std::vector<int>& array, long long& comparisons) {
    if (array.empty()) return;
    mergeArray(array, 0, array.size() - 1);
    comparisons = countCompare;
}

void mergeTime(std::vector<int>& array, int left, int mid, int right) {
    int first1 = left, last1 = mid;
    int first2 = mid + 1, last2 = right;

    int index = left;
    while ((first1 <= last1) && (first2 <= last2)) {
        if (array[first1] < array[first2]) tempArr[index++] = array[first1++];
        else tempArr[index++] = array[first2++];
    }

    while (first1 <= last1) tempArr[index++] = array[first1++];
    while (first2 <= last2) tempArr[index++] = array[first2++];

    for (int i = left; i <= right; ++i) {
        array[i] = tempArr[i];
    }
}

void mergeArrayTime(std::vector<int>& array, int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeArrayTime(array, left, mid);
    mergeArrayTime(array, mid + 1, right);

    mergeTime(array, left, mid, right);
}

void mergeSortTime(std::vector<int>& array) {
    if (array.empty()) return;
    mergeArrayTime(array, 0, array.size() - 1);
}