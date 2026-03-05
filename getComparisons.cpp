#include <iostream>
#include <string>
#include "sortAlgorithms/sort.h"
#include <fstream>
#include "dataGeneration.h"
#include "commandProcessing.h"

using namespace std;

long long getAlgorithm(string Name, const vector<int>& Array){
    vector<int> Tmp = Array;
    long long Comparisons = 0;

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

    return Comparisons;
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
