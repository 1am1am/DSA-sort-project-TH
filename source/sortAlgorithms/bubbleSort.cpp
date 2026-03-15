#include <iostream>
#include <vector>
#include "sort.h"

using namespace std;
<<<<<<< HEAD
// void bubbleSort(std::vector<int>& array, long long& comparisons) {
//     bool unsorted = true;
//     int pas = 0 ; 
//     int n = array.size();
//     while (unsorted) {
//         unsorted = false;
//         pas++;
//         for (int i = 0 ; ++ comparisons && i < n - pas; i++ ) {
//             if (++ comparisons && array[i] > array[i+1]) {
//                 swap(array[i], array[i+1]);
//                 unsorted = true;    
//             }
//         }
//     }
// }

// void bubbleSortTime(std::vector<int>& array) {
//     bool unsorted = true;
//     int pas = 0 ; 
//     int n = array.size();
//     while (unsorted) {
//         unsorted = false;
//         pas++;
//         for (int i = 0; i < n - pas; i++ ) {
//             if (array[i] > array[i+1]) {
//                 swap(array[i], array[i+1]);
//                 unsorted = true;    
//             }
//         }
//     }
// }





void bubbleSort(vector<int>&array, long long& comparisons) {
    int n  = array.size();
    for (int i = 0 ; ++comparisons && i < n-1; i++) {
        for (int j = 0 ; ++comparisons && j < n - 1 - i ; j++ ) {
            if  ( ++comparisons && array[j ] > array [j+1  ] ) {
                swap(array[i], array[i+1]);
=======
void bubbleSort(std::vector<int>& array, long long& comparisons) {
    int n = array.size();
    for(int i = 0; ++ comparisons && i < n; ++i) {
        for (int j = 0 ; ++ comparisons && j < n - i; j++ ) {
            if (++ comparisons && array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
>>>>>>> c74b738388e0b2f679d478643196bc65bb0bb4d7
            }
        }
    }
}

<<<<<<< HEAD

void bubbleSortTime(vector<int>&array) {
    int n  = array.size();
    for (int i = 0 ;i < n-1; i++) {
        for (int j = 0 ; j < n - 1 - i ; j++ ) {
            if  (array[j ] > array [j+1  ] ) {
                swap(array[i], array[i+1]);
=======
void bubbleSortTime(std::vector<int>& array) {
    int n = array.size();
    for(int i = 0; i < n; ++i) {
        for (int j = 0 ; j < n - i; j++ ) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
>>>>>>> c74b738388e0b2f679d478643196bc65bb0bb4d7
            }
        }
    }
}
