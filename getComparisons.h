#ifndef SETMOD_H
#define SETMOD_H

#include <string>
#include <vector>
using namespace std;

long long getAlgorithm(string Name, const vector<int>& Array);
void getComparisons(Command command);
void readFile(vector<int>& Array, Command& command);
void makeInput(vector<int>& Array, Command& command);

#endif