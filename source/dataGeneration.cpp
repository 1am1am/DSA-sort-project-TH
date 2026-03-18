#include "consoleUI.h"
#include "getComparisonsAndTime.h"
#include "commandProcessing.h"
#include "dataGeneration.h"
#include "sortAlgorithms/sort.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <vector>
using namespace std;

template <class T>
void Swap(T &a, T &b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Function to generate an array with random data
vector<int> GenerateRandomData(int n)
{
	srand((unsigned int)time(NULL));
	vector<int> array;
	for (int i = 0; i < n; i++)
	{
		array.push_back (rand()%n);
	}
	return array;
}

// Function to generate an array with ascending order data
vector<int> GenerateSortedData( int n)
{	
	vector<int> array;
	for (int i = 0; i < n; i++)
	{
		array.push_back (i);
	}

	return array;
}

// Function to generate an array with descending order data
vector<int> GenerateReverseData( int n)
{	
	vector<int> array;
	for (int i = 0; i < n; i++)
	{
		array.push_back(n - 1 - i);
	}

	return array;
}

// Function to generate an array with nearly sorted data
vector<int> GenerateNearlySortedData(int n) {
	vector<int> array;
	for (int i = 0; i < n; i++)
	{
		array.push_back(i);
	}
	srand((unsigned int) time(NULL));
	for (int i = 0; i < 10; i ++)
	{
		int r1 = rand()%n;
		int r2 = rand()%n;
		Swap(array[r1], array[r2]);
	}

	return array;
}

vector<int> GenerateData(int n , string dataType) {
	vector<int> array;
	if (dataType == "-sorted") {
		array = GenerateSortedData(n);
	}
	else if (dataType == "-nsorted" ) {
		array = GenerateNearlySortedData(n);
	}
	else if (dataType == "-rev") {
		array = GenerateReverseData(n);
	}
	else if (dataType =="-rand" ) {
		array = GenerateRandomData(n);
	}
	else {
		cout << "Invalid dataset type input \n";
	}
	return array;
}

void writeFile(Command command, string filename) {
	ofstream fout(filename);
	if (!fout.is_open()) {
		cout << "Error!" << endl;
	}

	fout << command.inputSize << endl;
	vector<int> array = GenerateData(command.inputSize, command.inputOrder);
	for (int x: array ){
		fout << x << " ";
	}
	fout.close();
}
void writeArrayToFile(string filename, int size, const vector<int>& array) {
	ofstream fout(filename);
	if (fout.is_open()) {
		fout << size << "\n";
		for (size_t i = 0; i < array.size(); i++) {
			fout << array[i];
			if (i < array.size() - 1) fout << " ";
		}
		fout.close();
	} else {
		cout << "Cannot open " << filename << "\n";
	}
}