#include "consoleUI.h"
#include "getComparisonsAndTime.h"
#include "commandProcessing.h"
#include <iostream>
#include <string>
#include "dataGeneration.h"



int main(int argc, char* argv[]) {
    //g++ main.cpp -o 07.exe

<<<<<<< HEAD
    std::vector<std::string> commandLine(argv, argv + argc);

    Command command = commandProcessing(argc, commandLine);
    getComparisonsAndTime(command);

    print(command);

=======
    // std::vector<std::string> commandLine(argv, argv + argc);
    // commandProcessing(argc, commandLine);
    string filename1 = "inputFiles/rev_10000.txt";
    writeFile(filename1,"-rev",10000);
    filename1 = "inputFiles/rev_30000.txt";
    writeFile(filename1,"-rev",30000);
    filename1 = "inputFiles/rev_50000.txt";
    writeFile(filename1,"-rev",50000);
    filename1 = "inputFiles/rev_100000.txt";
    writeFile(filename1,"-rev",100000);
    filename1 = "inputFiles/rev_300000.txt";
    writeFile(filename1,"-rev",300000);
    filename1 = "inputFiles/rev_500000.txt";
    writeFile(filename1,"-rev",500000);
    
    cout << "check";
    
>>>>>>> 26311d6d3973a60e66b7edefa3ad159c801809fe
    return 0;
}