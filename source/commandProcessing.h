#ifndef COMMAND_PROCESSING_H
#define COMMAND_PROCESSING_H

#include <vector>
#include <string>

struct Command{
    std::string mode;
    std::string algorithm1;
    std::string algorithm2;
    std::string inputFile;
    int inputSize;
    std::string inputOrder;
    std::string outputParameter;
    double runningTime1, runningTime2;
    long long comparisons1, comparisons2;
    Command() {
        runningTime1 = runningTime2 = 0;
        comparisons1 = comparisons2 = 0;
        inputOrder = "-all";
    }
};

Command commandProcessing(int argc, std::vector<std::string> argv);

#endif