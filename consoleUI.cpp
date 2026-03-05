#include "consoleUI.h"
#include <iostream>
#include <string>

void consoleUI(Parameter parameter) {
    std::cout << "Algorithm: " << parameter.algorithm << '\n';
    std::cout << "Input size: " << parameter.inputSize << '\n';
    std::cout << "Input order: " << parameter.inputOrder << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Running time: " << parameter.runningTime << '\n';
    std::cout << "Comparisons: " << parameter.comparisons << '\n';
}