#ifndef _BubleWithIvers_H_
#define _BubleWithIvers_H_
#include "Lines.h"

void bubleWithAivers(){
    std::cout << "Buble with Aivers\n" << LINE;
    for(int SIZE = 100; SIZE != 1000000; SIZE *= 10){
        int *data = new int[SIZE];
        for(int i = 0; i < SIZE; i++) data[i] = i;
        std::cout << "SIZE = " << SIZE << " | TIME = ";
        long long int Cf = 0;
        long long int Mf = 0;
        auto start = std::chrono::high_resolution_clock::now();

        //start
        for (int i = 0; i < SIZE - 1; i++) {
            for (int j = 0; j < SIZE - i - 1; j++) {
                //Cf++;
                if (data[j] > data[j + 1]) {
                    int temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                    //Mf+=3;
                }
            }
        }
        //end

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
        std::cout << duration.count() << " nanosec | Cf+Mf = " << Cf << "+" << Mf << std::endl;
        delete[] data;
    }
    std::cout << LINE;
}

#endif