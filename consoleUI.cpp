#include "consoleUI.h"
#include <iostream>
#include <string>

void outputParameter(std::string outputType, Command command) {
    if (outputType == "-time") {
        std::cout << "Running time: " << command.runningTime1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.runningTime2) : "") << '\n';
    } else if (outputType == "-comp") {
        std::cout << "Comparisons: " << command.runningTime1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.comparisons2) : "") << '\n';
    } else if (outputType == "-both") {
        std::cout << "Running time: " << command.runningTime1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.runningTime2) : "") << '\n';
        std::cout << "Comparisons: " << command.runningTime1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.comparisons2) : "") << '\n';
    }
}

void consoleUI(Command command) {
    std::cout << "Algorithm: " << command.algorithm1 << (!command.algorithm2.empty() ? " | " : "") << command.algorithm2 << '\n';
    std::cout << "Input size: " << command.inputSize << '\n';
    std::cout << "Input order: " << command.inputOrder << '\n';
    std::cout << "-------------------------\n";
    outputParameter(command.outputParameter, command);
}