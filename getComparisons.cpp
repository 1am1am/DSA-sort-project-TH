#include <iostream>
#include <string>
#include "sortAlgorithms/sort.h"
#include <fstream>
#include "dataGeneration.h"
#include "commandProcessing.h"
#include <chrono>
#include "commandProcessing.h"

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
    fin >> command.inputFile;
    for(int i = 0; i < command.inputSize; ++i){
        int Number; fin >> Number;
        Array.push_back(Number);
    }
    fin.close();
}

void makeInput(vector<int>& Array, Command& command){
    int* Array2 = new int[command.inputSize];
    if(command.inputOrder == "-rand") (Array2, command.inputSize, 0);
    if(command.inputOrder == "-sorted") (Array2, command.inputSize, 1);
    if(command.inputOrder == "-rev") (Array2, command.inputSize, 2);
    if(command.inputOrder == "-nsorted") (Array2, command.inputSize, 3);
    for(int i = 0; i < command.inputSize; ++i) Array.push_back(Array2[i]);
    delete[]Array2;
}

void getComparisons(Command& command){
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
