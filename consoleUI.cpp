#include "consoleUI.h"
#include "getComparisonsAndTime.h"
#include "commandProcessing.h"
#include "dataGeneration.h"
#include "sortAlgorithms/sort.h"
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

std::string nameInputOrder(std::string inputOrder) {
    if (inputOrder == "-sorted") return "Sorted";
    if (inputOrder == "-nsorted") return "Nearly Sorted";
    if (inputOrder == "-rev") return "Reverse Sorted";
    return "Randomized";
}

void consoleUI(Command command) {
    std::cout << "Algorithm: " << command.algorithm1 << (!command.algorithm2.empty() ? " | " : "") << command.algorithm2 << '\n';
    if (!command.inputFile.empty()) std::cout << "Input file: " << command.inputFile << '\n';
    std::cout << "Input size: " << command.inputSize << '\n';
    if (command.inputFile.empty()) std::cout << "Input order: " << nameInputOrder(command.inputOrder) << '\n';
    std::cout << "-------------------------\n";
    outputParameter(command.outputParameter, command);
}

void print(Command& command) {
    if (command.inputOrder == "-all" && command.inputFile.empty()) {
        command.inputOrder = "-sorted";
        consoleUI(command);

        command.inputOrder = "-nsorted";
        consoleUI(command);

        command.inputOrder = "-rev";
        consoleUI(command);

        command.inputOrder = "-rand";
        consoleUI(command);
    } else {
        consoleUI(command);
    }
}