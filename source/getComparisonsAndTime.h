#ifndef GETCOMPARISONS_H 
#define GETCOMPARISONS_H

#include <string>
#include <vector>
#include "commandProcessing.h"
using namespace std;

long long getAlgorithm(string Name, const vector<int>& Array,double &Time);
void getComparisonsAndTime(Command& command);
void readFile(vector<int>& Array, Command& command);
void makeInput(vector<int>& Array, Command& command);

#endif