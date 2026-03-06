#include "consoleUI.h"
#include "getComparisonsAndTime.h"
#include "commandProcessing.h"
#include "dataGeneration.h"
#include "sortAlgorithms/sort.h"
#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

long long getAlgorithm(string Name, const vector<int>& Array,double &Time){
    vector<int> Tmp = Array;
    long long Comparisons = 0;
    auto start = chrono::high_resolution_clock::now();

    if("selection-sort" == Name) selectionSort(Tmp, Comparisons);
    if("insertion-sort" == Name) insertionSort(Tmp, Comparisons);
    if("shell-sort" == Name) shellSort(Tmp, Comparisons);
    if("bubble-sort" == Name) bubbleSort(Tmp, Comparisons);
    if("heap-sort" == Name) heapSort(Tmp, Comparisons);
    if("merge-sort" == Name) mergeSort(Tmp, Comparisons);
    if("quick-sort" == Name) quickSort(Tmp, Comparisons);
    if("radix-sort" == Name) radixSort(Tmp, Comparisons);
    if("counting-sort" == Name) countingSort(Tmp, Comparisons);
    if("binary-insertion-sort" == Name) binaryInsertionSort(Tmp, Comparisons);
    if("shaker-sort" == Name) shakerSort(Tmp, Comparisons);
    if("flash-sort" == Name) flashSort(Tmp, Comparisons);

    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double, milli> duration = end - start;
    Time = duration.count();
    return Comparisons;
}

void readFile(vector<int>& Array, Command& command){
    ifstream fin;
    fin.open(command.inputFile);
    if(!fin.is_open()){
        cout << "Error!\n";
        command.inputSize = 0;
        return;
    }
    fin >> command.inputSize;
    for(int i = 0; i < command.inputSize; ++i){
        int Number; fin >> Number;
        Array.push_back(Number);
    }
    fin.close();
}

void makeInput(vector<int>& Array, Command& command){
    if(command.inputOrder == "-rand") Array = GenerateData(command.inputSize, "-rand");
    if(command.inputOrder == "-sorted") Array = GenerateData(command.inputSize, "-sorted");
    if(command.inputOrder == "-rev") Array = GenerateData(command.inputSize, "-rev");
    if(command.inputOrder == "-nsorted") Array = GenerateData(command.inputSize, "-nsorted");
}

void getComparisonsAndTime(Command& command){
    double time1 = 0.0, time2 = 0.0;
    vector<int> Array; 
    if(command.inputFile != "") readFile(Array, command);
    else makeInput(Array, command);
    long long Comparison1 = getAlgorithm(command.algorithm1, Array,time1), Comparison2 = 0;
    if(command.mode == "-c") Comparison2 = getAlgorithm(command.algorithm2, Array,time2);
    command.comparisons1 = Comparison1;
    command.comparisons2 = Comparison2;
    command.runningTime1 = time1;
    command.runningTime2 = time2;
}
