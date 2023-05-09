#include "sorts.h"
#include <ctime>
#include <chrono>
#include <functional>
#include <string>
using namespace std;

int main() {
    int size = 100;
    float timer;
    float check[6]{0,0,0,0,0,0}; // массив времени

    void (*func[6])(int *, int) ={countSort,quickSort, mergeSort, bubbleSort, insertSort,gnomeSort};
    FILE *flog;
    flog = fopen("result.txt", "w");
    fprintf(flog, "%s\t%s\t%s\t%s\t%s\t%s\t%s\n", "size","countSort","quickSort","mergeSort", "bubbleSort","insertSort","gnomeSort");

    while (size <= 10000000) {
        fprintf(flog, "%d\t",size);
        srand(time(nullptr));

        int *arr = new int[size];

        chrono::duration<float> res_time; // переменная времени

        for (int h = 0; h<6; h++) {
            if(check[h]<=20) {
                for (int q = 0; q < size; q++) {
                    arr[q] = rand();
                }
                auto start = std::chrono::high_resolution_clock::now(); //
                func[h](arr,size);
                auto end = std::chrono::high_resolution_clock::now();
                res_time = end - start;

                timer=res_time.count();;
                check[h]=timer;
                fprintf(flog,"%f\t",timer);
            }
        }
        fprintf(flog,"\n");
        size = size + size/6;
        delete[] arr;
    }
    fclose(flog);
    return 0;
}
