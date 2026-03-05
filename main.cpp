#include "consoleUI.h"
#include "getComparisonsAndTime.h"
#include "commandProcessing.h"
#include <iostream>
#include <string>



int main(int argc, char* argv[]) {
    //g++ main.cpp -o 07.exe

    std::vector<std::string> commandLine(argv, argv + argc);

    Command command = commandProcessing(argc, commandLine);
    getComparisonsAndTime(command);

    print(command);

    return 0;
}