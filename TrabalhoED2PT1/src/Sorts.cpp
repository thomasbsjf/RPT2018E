#include "Sorts.h"
#include <algorithm>
#include <iostream>
Sorts::Sorts()
{
    numRegistros = 0;
    contadorCompara = 0;
}

Sorts::~Sorts()
{

}

void Sorts::merging(int vet[], int inicio, int meio, int fim)
{
    int i, j, k, *aux;
    i = inicio;
    j = fim;
    k = 0;
    aux = new int[fim-inicio];

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
    while(j<= fim)
    {
        aux[k]= vet[j];
        j++;
        k++;
    }
    for(int p = inicio; p<= fim; p++)
    {
        vet[p] = aux[p];
    }
}

void Sorts::mergeSort(int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = (inicio + fim)/2;
        mergeSort(vet,inicio,meio);
        mergeSort(vet,meio +1,fim);
        merging(vet, inicio, meio, fim);
    }
}

void Sorts::insertionSort(int vet[], int tam)
{
    zeraContadorCompara();
    zeraNumRegistros();
    for(int i = 1; i<= tam; i++)
    {
        int pivo = vet[i];
        addNumRegistros();
        int j = i - 1;
        addNumRegistros();
        while(j>=0 && vet[j] > pivo)
        {
            addContadorCompara();
            if(vet[j] > pivo)
            {
                addContadorCompara();
                vet[j+1] = vet[j];
                addNumRegistros();
                j--;
            }
        }
        vet[j+1] = pivo;
        addNumRegistros();
    }
    imprimeValores();
}

void Sorts::constroiHeap(int vet[], int tam, int raiz)
{
    int ram, valor; // ram = ramificação
    valor = vet[raiz];

    while(raiz < (tam/2))
    {
        ram = 2*raiz + 1;
        if(ram < tam -1 && vet[ram] < vet[ram +1])
        {
            ram++;
        }
        if(valor >= vet[ram])
        {
            break;
        }
        vet[raiz] = vet[ram];
        raiz = ram;
    }
    vet[raiz] = valor;
}

void Sorts::heapSort(int vet[], int tam) // FAZER!
{
    //int troca;
    for(int i = tam/2; i>= 0; i--)
    {
        constroiHeap(vet,tam, i);
    }
    while(tam >0)
    {
        std::swap(vet[0],vet[tam-1]);
        constroiHeap(vet,--tam,0);
    }
}

int Sorts::quickSepara(int vet[], int inicio, int fim)
{
    int esq, dir, aux, pivo;
    esq = inicio;
    addNumRegistros();
    dir = fim;
    addNumRegistros();
    pivo = vet[inicio];
    addNumRegistros();
    while(esq<dir)
    {
        addContadorCompara();
        while(vet[esq]<= pivo)
        {
            addContadorCompara();
            esq++;
            addNumRegistros();
        }
        while(vet[dir]> pivo)
        {
            addContadorCompara();
            dir--;
            addNumRegistros();
        }
        if(esq<dir)
        {
            addContadorCompara();
            aux = vet[esq];
            addNumRegistros();
            vet[esq] = vet[dir];
            addNumRegistros();
            vet[dir] = aux;
            addNumRegistros();
        }
    }
    vet[inicio] = vet[dir];
    addNumRegistros();
    vet[dir] = pivo;
    addNumRegistros();
    return dir;
}

int Sorts::quickSeparaMediana(int vet[], int inicio, int fim, int mediana)
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

void Sorts::quickSort(int vet[],int inicio, int fim)
{
    if(inicio < fim)
    {
        int indicePivo = quickSepara(vet,inicio,fim);
        quickSort(vet,inicio,indicePivo-1);
        quickSort(vet,indicePivo+1,fim);
    }

}

void Sorts::quickSortInsertion(int vet[], int inicio, int fim)
{
    int tamanho = fim-inicio;
    insertionSort(vet, tamanho);
    imprimeValores();
}

double Sorts::medianaDeTres(int vet[],int inicio, int fim)
{

    int a = inicio + rand() % (fim-inicio);
    int b = inicio + rand() % (fim-inicio);
    int c = inicio + rand() % (fim-inicio);
    if(vet[a] > vet[b])
    {
        std::swap(a,b);
    }
    if(vet[a] > vet[c])
    {
        std::swap(a,c);
    }
    if(vet[b]> vet[c])
    {
        std::swap(b,c);
    }
    std::swap(b,c);
    return vet[c];
}

double Sorts::medianaDeCinco(int vet[], int inicio, int fim)  // FAZER
{
    return 0;
}

void Sorts::quickSortMediana(int vet[], int inicio, int fim)
{
    if(inicio <fim)
    {
        int mediana = medianaDeTres(vet, inicio, fim);
        int indicePivo = quickSeparaMediana(vet, inicio, fim, mediana);
        quickSort(vet,inicio,indicePivo-1);
        quickSort(vet,indicePivo+1,fim);
    }
}

void Sorts::imprimeValores()
{
    std::cout << "Numero de comparacoes: " << contadorCompara << std::endl;
    std::cout << "Copias de Registros: " << numRegistros << std::endl;
}
