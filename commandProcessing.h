#ifndef INPUT_PROCESSING_H
#define INPUT_PROCESSING_H

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
};

Command inputProcessing(int argc, std::vector<std::string> argv);

#endif