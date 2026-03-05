#ifndef CONSOLE_UI_H
#define CONSOLE_UI_H

#include "commandProcessing.h"

struct Parameter {
    std::string algorithm;
    int inputSize;
    std::string inputOrder;
    double runningTime;
    long long comparisons;

    Parameter(std::string _algorithm, int _inputSize, std::string _inputOrder, double _runningTime, long long _comparisons) {
        algorithm = _algorithm;
        inputSize = _inputSize;
        inputOrder = _inputOrder;
        runningTime = _runningTime;
        comparisons = _comparisons;
    }
};

void consoleUI(char* algorithm, char* inputSize, char* inputOrder, double runningTime, long long comparisons);

#endif