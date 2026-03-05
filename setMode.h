#ifndef SETMOD_H
#define SETMOD_H

#include <string>
#include <vector>
using namespace std;

long long getAlgorithm(string Name, const vector<int>& Array);
void setMode(string Mode, string Algorithm1, string Algorithm2, string InputFile, int InputSize, string InputOrder, string Output);

#endif