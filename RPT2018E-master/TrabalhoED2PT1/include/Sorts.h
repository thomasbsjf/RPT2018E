#ifndef SORTS_H
#define SORTS_H
#include <algorithm>

class Sorts
{
    public:
        Sorts();
        virtual ~Sorts();

        /**Funcoes publicas QuickSort e InsertionSort**/
        void quickSort(int vet[], int, int);
        void quickSortMedianaTres(int vet[], int, int);
        void quickSortInsertion(int vet[], int, int);
        double medianaDeTres(int vet[], int inicio, int fim);
        void insertionSort(int vet[], int n);
        void manualSortQuick(int vet[], int inicio, int fim);
        int numeroAleatorio(int menor, int maior);

        /**Funcoes heapSort**/
        void heapSort(int vet[], int tam);

        /**Funcoes publicas heapSort**/
        void mergeSort(int vet[], int inicio, int fim);

        /**Funcoes publicas shellSort**/
        void shellSort(int *vet, int tam);

        int getContadorCompara() {return contadorCompara;};
        void addContadorCompara() {contadorCompara += 1;}
        int getNumRegistros() {return numRegistros;};
        void addNumRegistros() {numRegistros += 1;}
        void zeraContadorCompara() {contadorCompara = 0;}
        void zeraNumRegistros() {numRegistros = 0;}

        /**Funcoes impressao de comparacoes e registros**/
        void imprimeValores();

    private:
        /**Funcoes privadas mergeSort**/
        void merging(int vet[],int,int,int);

        /**Funcoes privadas heapSort**/
        void constroiHeap(int vet[], int, int);

        /**Funcoes privadas quickSort heapSort**/
        int quickSepara(int vet[], int, int);
        int quickSeparaMediana(int vet[],int, int, int);

        /**Atributos privados da classe**/
        int contadorCompara;
        int numRegistros;
};

#endif // SORTS_H
