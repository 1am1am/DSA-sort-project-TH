#include "consoleUI.h"
#include <iostream>
<<<<<<< HEAD
#include <string>

struct Input{
    std::string mode;
    std::string algorithm1;
    std::string algorithm2;
    std::string inputFile;
    int inputSize;
    std::string inputOrder;
    std::string outputParameter;
};

int main(int argc, char* argv[]) {
    //g++ main.cpp -o 07.exe
    
    Input input;
    
=======
#include "setMode.h"

int main(int argc, char* argv[]) {
    //g++ main.cpp -o 07.exe
    setMode(argv[0], )
>>>>>>> c0f9ab6f765cd0aed8b1443563116161b93a0ec6
    return 0;
}