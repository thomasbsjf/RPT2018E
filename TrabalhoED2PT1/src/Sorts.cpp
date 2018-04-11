#include "Sorts.h"
#include <algorithm>

Sorts::Sorts()
{

}

Sorts::~Sorts()
{

}

void Sort::merging(int vet[], int inicio, int meio, int fim)
{
    int i, j, k, *aux;
    i = inicio;
    j = fim;
    k = 0;
    aux = new int[(inicio+fim)+1];

    while(i <= meio && j <= fim)
    {
        if(vet[i]< vet[j])
        {
            aux[k] = vet[i];
            i++;
        }
        else
        {
            aux[k] = vet[j];
            j++;
        }
        k++;
    }
    while(i<= meio)
    {
        aux[k] = vet[i];
        i++;
        k++;
    }
    while(j>= fim)
    {
        aux[k]= vet[j];
        j++;
        k++;
    }
    k = 0;
    i = inicio;
    while(i<= fim)
    {
        vet[i] = aux[k];
        i++;
        k++;
    }
}

void Sort::mergeSort(int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = (inicio + fim)/2;
        mergeSort(vet,inicio,meio);
        mergeSort(vet,meio +1,fim);
        merging(vet, inicio, meio, fim);
    }
}

void Sort::insertionSort(int vet[], int tam)
{
    for(int i = 1; i<= tam; i++)
    {
        int pivo = vet[i];
        int j = i - 1;
        while(j>=0 && vet[j] > pivo)
        {
            vet[j+1] = vet[j];
            j--;
        }
        vet[j+1] = pivo;
    }
}

void Sort::heapSort(int v[], int tam, int raiz)
{
    int ram, valor; // ram = ramificação
    valor = v[raiz];

    while(raiz < (tam/2))
    {
        ram = 2*raiz + 1;
        if(ram < tam -1 && v[ram] < v[ram +1])
        {
            ram++;
        }
        if(valor >= v[ram])
        {
            break;
        }
        v[raiz] = v[ram];
        raiz = ram;
    }
    v[raiz] = valor;
}

void Sort::heapify() // FAZER!
{
    
}

int Sort::quickSepara(int vet[], int inicio, int fim)
{
    int esq, dir, aux, pivo;
    esq = inicio;
    dir = fim;
    pivo = vet[inicio];
    while(esq<dir)
    {
        while(vet[esq]<= pivo)
        {
            esq++;
        }
        while(vet[dir]> pivo)
        {
            dir--;
        }
        if(esq<dir)
        {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

int Sort::quickSepara(int vet[], int inicio, int fim, int mediana)
{
    int esq, dir, aux, pivo;
    esq = inicio;
    dir = fim;
    pivo = vet[mediana];
    while(esq<dir)
    {
        while(vet[esq]<= pivo)
        {
            esq++;
        }
        while(vet[dir]> pivo)
        {
            dir--;
        }
        if(esq<dir)
        {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }
    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}

void Sort::quickSort(int vet[],int inicio, int fim)
{
    if(inicio < fim)
    {
        int indicePivo = quickSepara(vet,inicio,fim);
        quickSort(vet,inicio,indicePivo-1);
        quickSort(vet,indicePivo+1,fim);
    }
}

void Sort::quickSortInsertion(int vet[], int inicio, int fim)
{
    int tamanho = fim-inicio;
    if(tamanho<10)
    {
        insertionSort(vet, tamanho);
    }else{
        quickSort(vet, inicio, fim);
    }
}

double Sort::medianaDeTres(int vet[],int inicio, int fim)
{
    int meio = (inicio+fim)/2;

    if(vet[inicio] > vet[meio])
    {
        std::swap(inicio,meio);
    }
    if(vet[inicio] > vet[fim])
    {
        std::swap(inicio,fim);
    }
    if(vet[meio]> vet[fim])
    {
        std::swap(meio,fim);
    }
    std::swap(meio,fim);
    return vet[fim];
}

double Sort::medianaDeCinco(int vet[], int inicio, int fim){ // FAZER
    
}

void Sort::quickSortMediana(int vet[], int inicio, int fim)
{
    if(inicio <fim)
    {
        int mediana = medianaDeTres(vet, inicio, fim);
        int indicePivo = quickSepara(vet, inicio, fim, mediana);
        quickSort(vet,inicio,indicePivo-1);
        quickSort(vet,indicePivo+1,fim);
    }
}

