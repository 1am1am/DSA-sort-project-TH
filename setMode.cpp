#include <iostream>
#include <string>
#include "sort.h"
#include <fstream>
#include "dataGeneration.h"

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

void setMode(string Mode, string Algorithm1, string Algorithm2, string InputFile, int InputSize, string InputOrder, string Output){
    vector<int> Array; 
    if(InputFile != ""){
        ifstream fin;
        fin.open(InputFile);
        fin >> InputSize;
        for(int i = 0; i < InputSize; ++i){
            int Number; fin >> Number;
            Array.push_back(Number);
        }
        fin.close();
    }
    else{
        int* Array2 = new int[InputSize];
        if(InputOrder == "-rand") (Array2, InputSize, 0);
        if(InputOrder == "-sorted") (Array2, InputSize, 1);
        if(InputOrder == "-rev") (Array2, InputSize, 2);
        if(InputOrder == "-nsorted") (Array2, InputSize, 3);
        for(int i = 0; i < InputSize; ++i) Array.push_back(Array2[i]);
        delete[]Array2;
    }
    int Comparision1 = getAlgorithm(Algorithm1, Array), Comparision2 = 0;
    if(Mode == "-c"){
        Comparision2 = getAlgorithm(Algorithm2, Array);
    }
}
