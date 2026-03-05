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
void radixSort(vector<int> &&array, long long &comparisons) {
	int size = array.size();
	int maxv = array[0];
	for (int i = 0; ++comparisons && i < size;i++) {
		if (maxv < array[i]) maxv = array[i];
	}
	Bucket buckets[10];
	for (int i = 0;++comparisons && i < 10; i++) {
		buckets[i].data = new int[size];
	}
	long long j = 1;
	while (maxv / j > 0) {
		++comparisons;
		for (int i = 0;++comparisons && i < 10; i++) {
			buckets[i].count = 0;
		}
		for (int i = 0;++comparisons && i < size;i++) {
			int digit = (array[i] / j % 10);
			int empty = buckets[digit].count;
			buckets[digit].data[empty] = array[i];
			buckets[digit].count++;
		}
		int dex = 0;
		for (int i = 0;++comparisons && i < 10; i++) {
			for (int l = 0;++comparisons && l < buckets[i].count;l++) {
				array[dex] = buckets[i].data[l];
				dex++;
			}
		}
		j *= 10;
	}
	for (int i = 0;++comparisons && i < 10;i++) {
		delete[] buckets[i].data;
	}
}