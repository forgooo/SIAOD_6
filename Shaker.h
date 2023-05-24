#ifndef _SHAKER_H_
#define _SHAKER_H_
#include "Lines.h"

int choiceShaker = 0;

void shakerSort() {
    choiceShaker++;
    if(choiceShaker == 4) return;
    srand(time(NULL));
    std::cout << "Shaker sort" << (choiceShaker == 1 ? "" : (choiceShaker == 2) ? " good" : " bad") << "\n" << LINE;
    for(int SIZE = 100; SIZE != 1000000; SIZE *= 10){
        int *data = new int[SIZE];
        for (int i = 0; i < SIZE; i++) data[i] = (choiceShaker == 1 ? rand() % SIZE : (choiceShaker == 2) ? i : SIZE - i);
        std::cout << "SIZE = " << SIZE << " | TIME = ";
        long long int Cf = 0;
        long long int Mf = 0;

        auto start = std::chrono::high_resolution_clock::now();
        //start
        bool swapped = true;
        int s = 0;
        int e = SIZE - 1;

        while (swapped) {
            swapped = false;
            for (int i = s; i < e; ++i) {
                Cf++;
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    swapped = true;
                    Mf+=3;
                }
            }
            if (!swapped) break;
            swapped = false;
            --e;
            for (int i = e - 1; i >= s; --i) {
                Cf++;
                if (data[i] > data[i + 1]) {
                    std::swap(data[i], data[i + 1]);
                    swapped = true;
                    Mf+=3;
                }
            }
            ++s;
        }
        //end

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout << duration.count() << " nanosec | Cf+Mf = " << Cf << "+" << Mf << std::endl;
        delete[] data;
    }
    std::cout << LINE;
    shakerSort();
}

#endif