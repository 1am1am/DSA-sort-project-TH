#include "sort.h"
#include <iostream>
#include <vector>

long long countCompare = 0;

void merge(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; ++countCompare && i < n1; ++i) L[i] = array[left + i];
    for (int i = 0; ++countCompare && i < n2; ++i) R[i] = array[mid + i + 1];

    int i = 0, j = 0, k = left;
    while (++countCompare && i < n1 && ++countCompare && j < n2) {
        if (++countCompare && L[i] < R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (++countCompare && i < n1) array[k++] = L[i++];
    while (++countCompare && j < n2) array[k++] = R[j++];
}

void mergeArray(std::vector<int>& array, int left, int right) {
    if (++countCompare && left >= right) return;

    int mid = (left + right) / 2;

    mergeArray(array, left, mid);
    mergeArray(array, mid + 1, right);

    merge(array, left, mid, right);
}

void mergeSort(std::vector<int>& array, long long& comparisons) {
    mergeArray(array, 0, array.size());
    comparisons = countCompare;
}

void mergeTime(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = array[left + i];
    for (int i = 0; i < n2; ++i) R[i] = array[mid + i + 1];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }

    while (i < n1) array[k++] = L[i++];
    while (j < n2) array[k++] = R[j++];
}

void mergeArrayTime(std::vector<int>& array, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeArrayTime(array, left, mid);
    mergeArrayTime(array, mid + 1, right);

    mergeTime(array, left, mid, right);
}

void mergeSortTime(std::vector<int>& array) {
    mergeArrayTime(array, 0, array.size());
}