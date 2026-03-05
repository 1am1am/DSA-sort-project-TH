#include "setMode.h"
#include "consoleUI.h"
#include "commandProcessing.h"
#include <iostream>
#include <string>

bool isNumber(const std::string& s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Input inputProcessing(int argc, std::vector<std::string> argv) {
    Input command;
    command.mode = argv[1];
    command.algorithm1 = argv[2];
    
    std::vector<int> array;
    long long comparisons1, comparisons2;
    if (command.mode == "-a") {
        if (isNumber(argv[4])) {
            command.inputSize = stoi(argv[4]);
        } else {
            command.inputFile = argv[4];
        }

        if (argc == 5) {
            command.outputParameter = argv[5];
        } else {
            command.inputOrder = argv[5];
            command.outputParameter = argv[6];
        }
    } else if (command.mode == "-c") {
        command.algorithm2 = argv[3];

        if (isNumber(argv[4])) {
            command.inputSize = stoi(argv[4]);
            command.inputOrder = argv[5];
        } else {
            command.inputFile = argv[4];
        }

    }
    return command;
}