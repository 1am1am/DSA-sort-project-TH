#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "sort.h"

using namespace std;
void selectionSort(std::vector<int>& array, long long& comparisons){
	int size = array.size();
	int i = 0;
	while (++comparisons && i < (size - 1)) {
		int min = i;
		for (int j = i + 1; ++comparisons && j < size;j++) {
			if (++comparisons && array[min] > array[j]) min = j;
		}
		swap(array[i], array[min]);
		i++;
	}
}