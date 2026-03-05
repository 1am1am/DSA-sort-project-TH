#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int partition(vector<int>& arr, int l, int r) { // lumoto
	int pivot;
	pivot = arr[r];
	int j = l - 1;
	for (int i = l;i < r;i++) {
		if (arr[i] <= pivot) {
			j++;
			swap(arr[j], arr[i]);
		}
	}
	j++;
	swap(arr[j], arr[r]);
	return j;
}

void quickSortArray(vector<int>& array, int l, int r) {// lumoto

	if (l < r) {
		int p = partition(array, l, r);
		quickSortArray(array, l, p - 1);
		quickSortArray(array, p + 1, r);
	}
}

void quickSort(vector<int>& array, long long& comparisons) {// lumoto
	quickSortArray(array, 0, array.size() - 1);
}


int main() {
	vector<int> arr = {3, 2, 1, 6, 5, 8, 4};
	long long index = 0;
	quickSort(arr, index);
	for (int i = 0;i < arr.size();i++) {
		cout << arr[i] << " ";
	}
	return 0;
}