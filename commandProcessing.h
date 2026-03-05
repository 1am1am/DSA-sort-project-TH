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
    double time1, time2;
    long long comparisons1, comparisons2;

};

Command commandProcessing(int argc, std::vector<std::string> argv);

#endif