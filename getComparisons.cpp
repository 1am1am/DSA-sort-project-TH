#include <iostream>
#include <string>
#include "sortAlgorithms/sort.h"
#include <fstream>
#include "dataGeneration.h"
#include "commandProcessing.h"

using namespace std;

long long getAlgorithm(string Name, const vector<int>& Array){
    vector<int> Tmp = Array;
    long long Comparisions = 0;

    if("selection-sort" == Name) selectionSort(Tmp, Comparisions);
    if("insertion-sort" == Name) insertionSort(Tmp, Comparisions);
    if("shell-sort" == Name) shellSort(Tmp, Comparisions);
    if("bubble-sort" == Name) bubbleSort(Tmp, Comparisions);
    if("heap-sort" == Name) heapSort(Tmp, Comparisions);
    if("merge-sort" == Name) mergeSort(Tmp, Comparisions);
    if("quick-sort" == Name) quickSort(Tmp, Comparisions);
    if("radix-sort" == Name) radixSort(Tmp, Comparisions);
    if("counting-sort" == Name) countingSort(Tmp, Comparisions);
    if("binary-insertion-sort" == Name) binaryInsertionSort(Tmp, Comparisions);
    if("shaker-sort" == Name) shakerSort(Tmp, Comparisions);
    if("flash-sort" == Name) flashSort(Tmp, Comparisions);

    return Comparisions;
}

void getComparisons(Command command){
    vector<int> Array; 
    if(command.inputFile != ""){
        ifstream fin;
        fin.open(command.inputFile);
        fin >> command.inputFile;
        for(int i = 0; i < command.inputSize; ++i){
            int Number; fin >> Number;
            Array.push_back(Number);
        }
        fin.close();
    }
    else{
        int* Array2 = new int[command.inputSize];
        if(command.inputOrder == "-rand") (Array2, command.inputSize, 0);
        if(command.inputOrder == "-sorted") (Array2, command.inputSize, 1);
        if(command.inputOrder == "-rev") (Array2, command.inputSize, 2);
        if(command.inputOrder == "-nsorted") (Array2, command.inputSize, 3);
        for(int i = 0; i < command.inputSize; ++i) Array.push_back(Array2[i]);
        delete[]Array2;
    }
    int Comparision1 = getAlgorithm(command.algorithm1, Array), Comparision2 = 0;
    if(command.mode == "-c"){
        Comparision2 = getAlgorithm(command.algorithm2, Array);
    }
}
