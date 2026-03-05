#include "consoleUI.h"
#include "setMode.h"
#include "commandProcessing.h"
#include <iostream>
#include <string>



int main(int argc, char* argv[]) {
    //g++ main.cpp -o 07.exe

    std::vector<std::string> commandLine(argv, argv + argc);
    inputProcessing(argc, commandLine);
    
    return 0;
}