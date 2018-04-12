#ifndef SORTS_H
#define SORTS_H
#include <algorithm>

class Sorts
{
    public:
        Sorts();
        virtual ~Sorts();
        void quickSort(int *, int, int);
        void quickSortMediana(int *, int, int);
        void quickSortInsertion(int *, int, int);
        void insertionSort(int *, int n);
        void heapSort(int *, int, int);
        void heapify(); // FAZER!
        void mergeSort(int vet[], int inicio, int fim);
        double medianaDeTres(int vet[], int inicio, int fim);
        double medianaDeCinco(int vet[], int inicio, int fim);

    private:
        void merging(int *,int,int,int);
        int quickSepara(int *, int, int);
        int quickSeparaMediana(int [],int, int, int);
};

#endif // SORTS_H
