#ifndef DATAGENERATION_H
#define DATAGENERATION_H
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void Swap(T &a, T &b);
//-------------------------------------------------

// Function to generate an array with random data
vector<int> GenerateRandomData(int n);

// Function to generate an array with ascending order data
vector<int> GenerateSortedData(int n);

// Function to generate an array with descending order data
vector<int> GenerateReverseData(int n);

// Function to generate an array with nearly sorted data
vector<int> GenerateNearlySortedData( int n);

vector<int> GenerateData(int n, string dataType);
#endif