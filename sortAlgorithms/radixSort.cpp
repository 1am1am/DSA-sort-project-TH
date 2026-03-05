#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "sort.h"

using namespace std;
struct Bucket {
	int* data;
	int count;
};
void radixSort(int arr[], int size, long long& comparisions) {
	int maxv = arr[0];
	for (int i = 0; i < size;i++) {
		if (maxv < arr[i]) maxv = arr[i];
	}
	Bucket buckets[10];
	for (int i = 0; i < 10; i++) {
		buckets[i].data = new int[size];
	}
	long long j = 1;
	while (maxv / j > 0) {
		for (int i = 0; i < 10; i++) {
			buckets[i].count = 0;
		}
		for (int i = 0; i < size;i++) {
			int digit = (arr[i] / j % 10);
			int empty = buckets[digit].count;
			buckets[digit].data[empty] = arr[i];
			buckets[digit].count++;
		}
		int dex = 0;
		for (int i = 0; i < 10; i++) {
			for (int l = 0; l < buckets[i].count;l++) {
				arr[dex] = buckets[i].data[l];
				dex++;
			}
		}
		j *= 10;
	}
	for (int i = 0;i < 10;i++) {
		delete[] buckets[i].data;
	}
}