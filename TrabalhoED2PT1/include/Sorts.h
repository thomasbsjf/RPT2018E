#ifndef SORTS_H
#define SORTS_H
#include <algorithm>

class Sorts
{
    public:
        Sorts();
        virtual ~Sorts();
        void quickSort(int vet[], int, int);
        void quickSortMediana(int vet[], int, int);
        void quickSortInsertion(int vet[], int, int);
        void insertionSort(int vet[], int n);
        void constroiHeap(int vet[], int, int);
        void heapSort(int vet[], int tam);
        //void mergeSort(std::vector<int> vet, int inicio, int fim);
        void mergeSort(int vet[], int inicio, int fim);
        double medianaDeTres(int vet[], int inicio, int fim);
        double medianaDeCinco(int vet[], int inicio, int fim);
        int getContadorCompara() {return contadorCompara;};
        void addContadorCompara() {contadorCompara += 1;}
        int getNumRegistros() {return numRegistros;};
        void addNumRegistros() {numRegistros += 1;}
        void zeraContadorCompara() {contadorCompara = 0;}
        void zeraNumRegistros() {numRegistros = 0;}
        void imprimeValores();

    private:
        // merging(std::vector<int> vet,int,int,int);
        void merging(int vet[],int,int,int);
        int quickSepara(int vet[], int, int);
        int quickSeparaMediana(int vet[],int, int, int);
        int contadorCompara;
        int numRegistros;
};

#endif // SORTS_H
