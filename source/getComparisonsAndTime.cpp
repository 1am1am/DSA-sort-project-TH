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

long long getAlgorithm(string Name, const vector<int>& Array,double &Time,vector<int>& SortedArray){
    vector<int> Tmp = Array;
    long long Comparisons = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

    if("selection-sort" == Name){
        selectionSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        selectionSort(Tmp, Comparisons);
    }
    else if("insertion-sort" == Name){
        insertionSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        insertionSort(Tmp, Comparisons);
    }
    else if("shell-sort" == Name){
        shellSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        shellSort(Tmp, Comparisons);
    }
    else if("bubble-sort" == Name){
        bubbleSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        bubbleSort(Tmp, Comparisons);
    }
    else if("heap-sort" == Name){
        heapSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        heapSort(Tmp, Comparisons);
    }
    else if("merge-sort" == Name){
        mergeSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        mergeSort(Tmp, Comparisons);
    }
    else if("quick-sort" == Name){
        quickSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        quickSort(Tmp, Comparisons);
    }
    else if("radix-sort" == Name){
        radixSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        radixSort(Tmp, Comparisons);
    }
    else if("counting-sort" == Name){
        countingSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        countingSort(Tmp, Comparisons);
    }
    else if("binary-insertion-sort" == Name){
        binaryInsertionSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        binaryInsertionSort(Tmp, Comparisons);
    }
    else if("shaker-sort" == Name){
        shakerSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        shakerSort(Tmp, Comparisons);
    }
    else if("flash-sort" == Name){
        flashSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        flashSort(Tmp, Comparisons);
    }

    chrono::duration<double, milli> duration = end - start;
    Time = duration.count();
    SortedArray = Tmp;
    return Comparisons;
}

void readFile(vector<int>& Array, Command& command){
    ifstream fin;
    fin.open(command.inputFile);
    if(!fin.is_open()){
        cout << "Error!\n";
        command.inputSize = 0;
        exit(0);
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


long long getAlgorithm(string Name, const vector<int>& Array, double &Time, vector<int>& SortedArray){
    vector<int> Tmp = Array;
    long long Comparisons = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();

    if("selection-sort" == Name){
        selectionSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        selectionSort(Tmp, Comparisons);
    }
    else if("insertion-sort" == Name){
        insertionSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        insertionSort(Tmp, Comparisons);
    }

    else if("flash-sort" == Name){
        flashSortTime(Tmp);
        end = chrono::high_resolution_clock::now();
        Tmp = Array;
        flashSort(Tmp, Comparisons);
    }

    chrono::duration<double, milli> duration = end - start;
    Time = duration.count();
    

    SortedArray = Tmp; 

    return Comparisons;
}



void getComparisonsAndTime(Command& command){

    if (command.inputOrder == "-all") return; 

    double time1 = 0.0, time2 = 0.0;
    vector<int> Array; 
    
    if(command.inputFile != "") {
        readFile(Array, command);
    } else {
        makeInput(Array, command);
        

        if (command.isCommand3) {

            if (command.inputOrder == "-rand") writeArrayToFile("input_1.txt", command.inputSize, Array);
            else if (command.inputOrder == "-nsorted") writeArrayToFile("input_2.txt", command.inputSize, Array);
            else if (command.inputOrder == "-sorted") writeArrayToFile("input_3.txt", command.inputSize, Array);
            else if (command.inputOrder == "-rev") writeArrayToFile("input_4.txt", command.inputSize, Array);
        } else {

            writeArrayToFile("input.txt", command.inputSize, Array);
        }
    }
    
    vector<int> SortedArray1, SortedArray2;
    long long Comparison1 = getAlgorithm(command.algorithm1, Array, time1, SortedArray1), Comparison2 = 0;
    if(command.mode == "-c") Comparison2 = getAlgorithm(command.algorithm2, Array, time2, SortedArray2);
    
    command.comparisons1 = Comparison1;
    command.comparisons2 = Comparison2;
    command.runningTime1 = time1;
    command.runningTime2 = time2;


    if (command.mode == "-a" && !command.isCommand3) {
        writeArrayToFile("output.txt", command.inputSize, SortedArray1);
    }
}