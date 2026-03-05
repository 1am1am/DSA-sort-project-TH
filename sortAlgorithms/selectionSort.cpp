#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include "sort.h"

using namespace std;
void selectionSort(std::vector<int>& array, long long& comparisons){
	int size = array.size();
	int i = 0;
	while (i < (size - 1)) {
		int min = i;
		for (int j = i + 1; j < size;j++) {
			if (array[min] > array[j]) min = j;
		}
		swap(array[i], array[min]);
		i++;
	}
}