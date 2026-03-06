#include "consoleUI.h"
#include "getComparisonsAndTime.h"
#include "commandProcessing.h"
#include "dataGeneration.h"
#include "sortAlgorithms/sort.h"
#include <iostream>
#include <string>

void runTest() {
    std::vector<std::string> cmdLine(5);
    cmdLine[0] = "07.exe";
    std::vector<std::string> algorithm = {"selection-sort", "insertion-sort", "shell-sort", "bubble-sort", "heap-sort", "merge-sort", "quick-sort", "radix-sort", "counting-sort", "binary-insertion-sort", "shaker-sort", "flash-sort"};
    std::vector<std::string> size = {"10000", "30000", "50000", "100000", "300000", "500000"};
    for (std::string alg : algorithm) {
        std::cout << "############### DAY LA " << alg << " ###############\n"; 
        for (std::string x : size) {
            cmdLine[1] = "-a";
            cmdLine[2] = alg;
            cmdLine[3] = x;
            cmdLine[4] = "-both";
            Command cmd = commandProcessing(5, cmdLine);
            getComparisonsAndTime(cmd);
            print(cmd);
            std::cout << "\n";
        }
    }
}

int main(int argc, char* argv[]) {
    //g++ -g source/*.cpp source/sortAlgorithms/*.cpp -o source/07.exe

    // std::vector<std::string> commandLine(argv, argv + argc);

    // Command command = commandProcessing(argc, commandLine);
    // getComparisonsAndTime(command);
    
    // print(command);
    
    runTest();
    return 0;
}