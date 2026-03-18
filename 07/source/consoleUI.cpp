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
        std::cout << "Comparisions: " << command.comparisons1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.comparisons2) : "") << '\n';
    } else {
        std::cout << "Running time: " << command.runningTime1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.runningTime2) : "") << '\n';
        std::cout << "Comparisions: " << command.comparisons1 << (!command.algorithm2.empty() ? " | " : "") << (!command.algorithm2.empty() ? std::to_string(command.comparisons2) : "") << '\n';
    }
}

std::string algorithmInputOrder(std::string inputOrder) {
    if (inputOrder == "-sorted") return "Sorted";
    if (inputOrder == "-nsorted") return "Nearly Sorted";
    if (inputOrder == "-rev") return "Reverse Sorted";
    if (inputOrder == "-rand") return "Randomized";
    return "";
}

std::string nameAlgorithm(std::string algorithm) {
    if("selection-sort" == algorithm) return "Selection Sort";
    if("insertion-sort" == algorithm) return "Insertion Sort";
    if("shell-sort" == algorithm) return "Shell Sort";
    if("bubble-sort" == algorithm) return "Bubble Sort";
    if("heap-sort" == algorithm) return "Heap Sort";
    if("merge-sort" == algorithm) return "Merge Sort";
    if("quick-sort" == algorithm) return "Quick Sort";
    if("radix-sort" == algorithm) return "Radix Sort";
    if("counting-sort" == algorithm) return "Counting Sort";
    if("binary-insertion-sort" == algorithm) return "Binary Insertion Sort";
    if("shaker-sort" == algorithm) return "Shaker Sort";
    if("flash-sort" == algorithm) return "Flash Sort";
    return "";
}

void consoleUI(Command command) {
    std::cout << "Algorithm: " << command.algorithm1 << (!command.algorithm2.empty() ? " | " : "") << command.algorithm2 << '\n';
    if (!command.inputFile.empty()) std::cout << "Input file: " << command.inputFile << '\n';
    std::cout << "Input size: " << command.inputSize << '\n';
    if (command.inputFile.empty()) std::cout << "Input order: " << command.inputOrder << '\n';
    std::cout << "-------------------------\n";
    outputParameter(command.outputParameter, command);
}

void print(Command& command) {
    if (command.inputOrder == "-all" && command.inputFile.empty()) {
        command.isCommand3 = true;
        command.inputOrder = "-sorted";
        getComparisonsAndTime(command);
        consoleUI(command);
        std::cout << '\n';

        command.inputOrder = "-nsorted";
        getComparisonsAndTime(command);
        consoleUI(command);
        std::cout << '\n';

        command.inputOrder = "-rev";
        getComparisonsAndTime(command);
        consoleUI(command);

        command.inputOrder = "-rand";
        getComparisonsAndTime(command);
        consoleUI(command);
    } else {
        consoleUI(command);
    }
}