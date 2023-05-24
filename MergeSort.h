#ifndef _MERGESORT_H_
#define _MERGESORT_H_
#include"Lines.h"

int choiceMerge = 0;
long long Cf = 0;
long long Mf = 0;

void merge(int data[], int const left, int const mid, int const right)
{
    auto const subdataOne = mid - left + 1;
    auto const subdataTwo = right - mid;
    auto* leftdata = new int[subdataOne],
            * rightdata = new int[subdataTwo];
    for (auto i = 0; i < subdataOne; i++) {
        leftdata[i] = data[left + i];
        Mf++;
    }
    for (auto j = 0; j < subdataTwo; j++) {
        rightdata[j] = data[mid + 1 + j];
        Mf++;
    }

    auto indexOfSubdataOne= 0,
            indexOfSubdataTwo= 0;
    int indexOfMergeddata= left;
    while (indexOfSubdataOne < subdataOne && indexOfSubdataTwo < subdataTwo) {
        if (leftdata[indexOfSubdataOne] <= rightdata[indexOfSubdataTwo]) {
            data[indexOfMergeddata] = leftdata[indexOfSubdataOne];
            indexOfSubdataOne++;
        }
        else {
            data[indexOfMergeddata] = rightdata[indexOfSubdataTwo];
            indexOfSubdataTwo++;
        }
        indexOfMergeddata++;
        Cf++;
        Mf++;
    }
    while (indexOfSubdataOne < subdataOne) {
        data[indexOfMergeddata] = leftdata[indexOfSubdataOne];
        indexOfSubdataOne++;
        indexOfMergeddata++;
        Mf++;
    }
    while (indexOfSubdataTwo < subdataTwo) {
        data[indexOfMergeddata] = rightdata[indexOfSubdataTwo];
        indexOfSubdataTwo++;
        indexOfMergeddata++;
        Mf++;
    }
    delete[] leftdata;
    delete[] rightdata;
}


void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void startMergeSort(){
    choiceMerge++;
    if(choiceMerge == 4) return;
    srand(time(NULL));
    std::cout << "Merge sort" << (choiceMerge == 1 ? "" : (choiceMerge == 2) ? " good" : " bad") << "\n" << LINE;
    for(int SIZE = 100; SIZE != 1000000; SIZE *= 10){
        int *data = new int[SIZE];
        for (int i = 0; i < SIZE; i++) data[i] = (choiceMerge == 1 ? rand() % SIZE : (choiceMerge == 2) ? i : SIZE - i);
        int begin = 0; int end = SIZE -1;
        std::cout << "SIZE = " << SIZE << " | TIME = ";
        auto _start = std::chrono::high_resolution_clock::now();
        //start
        mergeSort(data, begin, end);
        //end;
        auto _end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start);
        std::cout << duration.count() << " nanosec | Cf+Mf = " << Cf << "+" << Mf << std::endl;
        Cf = 0; Mf = 0;
        delete[] data;
    }
    std::cout << LINE;
    startMergeSort();
}

#endif