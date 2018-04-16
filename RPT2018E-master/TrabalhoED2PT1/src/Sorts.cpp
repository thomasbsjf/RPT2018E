#include "Sorts.h"
#include <algorithm>
#include <iostream>
#include <time.h>
Sorts::Sorts()
{
    numRegistros = 0;
    contadorCompara = 0;
}

Sorts::~Sorts()
{

}


/** Intercala o mergeSort e ao fim o vetor está intercalado**/
void Sorts::merging(int vet[], int inicio, int meio, int fim)
{

    int i, j, k;
    int aux[(fim-inicio)];
    int tam = (fim-inicio);
    i = inicio;
    j = 1+meio;
    k = inicio;


    while(i <= meio && j <= fim)
    {
        addContadorCompara();
        if(vet[i]<= vet[j])
        {
            addContadorCompara();
            aux[k] = vet[i];
            addNumRegistros();
            i++;
        }
        else
        {
            aux[k] = vet[j];
            addNumRegistros();
            j++;
        }
        k++;
    }
    for(int q = i; q <=meio; ++q)
    {
        addContadorCompara();
        aux[k] = vet[q];
        addNumRegistros();
        k++;
    }
    for(int q = j; q<= fim; ++q)
    {
        addContadorCompara();
        aux[k] = vet[q];
        addNumRegistros();
        k++;
    }

    for(int q = inicio; q<= fim; ++q)
    {
        addContadorCompara();
        vet[q] = aux[q];
        addNumRegistros();
    }
}
/** Chama o mergeSort recursivamente até que o vetor esteja ordenado **/
void Sorts::mergeSort(int vet[], int inicio, int fim)
{
    if(inicio < fim)
    {
        int meio = (inicio + fim)/2;
        mergeSort(vet,inicio,meio);
        mergeSort(vet,meio+1,fim);
        merging(vet, inicio, meio, fim);
    }
}
/** Insertion Sort **/
void Sorts::insertionSort(int vet[], int tam)
{
    zeraContadorCompara();
    zeraNumRegistros();
    for(int i = 1; i< tam; i++)
    {
        int pivo = vet[i];
        addNumRegistros();
        int j = i - 1;
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

/** Constroi o Heap **/
void Sorts::constroiHeap(int vet[], int tam, int raiz)
{

    int ram, valor; // ram = ramificação
    valor = vet[raiz];
    addNumRegistros();

    while(raiz < (tam/2))
    {
        addContadorCompara();
        ram = 2*raiz + 1;
        if(ram < tam -1 && vet[ram] < vet[ram +1])
        {
            addContadorCompara();
            ram++;
        }
        if(valor >= vet[ram])
        {
            addContadorCompara();
            break;
        }
        vet[raiz] = vet[ram];
        addNumRegistros();
        raiz = ram;
        addNumRegistros();
    }
    vet[raiz] = valor;
    addNumRegistros();
}

/** Constroi o heap N vezes até a metade do tamanho do vetor**/
void Sorts::heapSort(int vet[], int tam) // FAZER!
{
    zeraContadorCompara();
    zeraNumRegistros();
    for(int i = tam/2; i>= 0; i--)
    {
        addContadorCompara();
        constroiHeap(vet,tam, i);
    }
    while(tam >0)
    {
        addContadorCompara();
        std::swap(vet[0],vet[tam-1]);
        constroiHeap(vet,--tam,0);
    }
}
/** Processo de ordenação do vetor utiliza o primeiro elemento do vetor com pivô**/
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
        }
        while(vet[dir]> pivo)
        {
            addContadorCompara();
            dir--;
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
/** Ordenação utilizando a mediana**/
int Sorts::quickSeparaMediana(int vet[], int inicio, int fim, int mediana)
{
    int esq, dir, aux, pivo;
    esq = inicio;
    addNumRegistros();
    dir = fim;
    addNumRegistros();
    pivo = vet[mediana];
    addNumRegistros();
    while(esq<dir)
    {
        addContadorCompara();
        while(vet[esq]<= pivo)
        {
            addContadorCompara();
            esq++;
        }
        while(vet[dir]> pivo)
        {
            addContadorCompara();
            dir--;
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
/** Quicksort comum**/
void Sorts::quickSort(int vet[],int inicio, int fim)
{
    if(inicio < fim)
    {
        int indicePivo = quickSepara(vet,inicio,fim);
        quickSort(vet,inicio,indicePivo);
        quickSort(vet,indicePivo+1,fim);
    }

}
/** quickSortInsertion, utiliza o InsertionSort ao inves do quick(Utilizado em vetores pequenos)**/
void Sorts::quickSortInsertion(int vet[], int inicio, int fim)
{
    int tamanho = fim-inicio;
    insertionSort(vet, tamanho);
    imprimeValores();
}
/** Calcula a mediana do vetor**/
double Sorts::medianaDeTres(int vet[],int inicio, int fim)
{
    int meio = (fim-inicio)-1/2;
    addNumRegistros();

    if(vet[inicio] > vet[meio])
    {
        addContadorCompara();
        std::swap(inicio,meio);
        addNumRegistros();
        addNumRegistros();
    }
    if(vet[inicio] > vet[fim])
    {
        addContadorCompara();
        std::swap(inicio,fim);
        addNumRegistros();
        addNumRegistros();
    }
    if(vet[meio]> vet[fim])
    {
        addContadorCompara();
        std::swap(meio,fim);
        addNumRegistros();
        addNumRegistros();
    }
    std::swap(meio,fim);
    addNumRegistros();
    addNumRegistros();
    return fim;
}
/** Quicksort com mediana**/
void Sorts::quickSortMedianaTres(int vet[], int inicio, int fim)
{
    if((fim - inicio) <= 3)
    {
        addContadorCompara();
        manualSortQuick(vet,inicio,fim);
    }
    else
    {
        int mediana = medianaDeTres(vet, inicio, fim);
        int indicePivo = quickSeparaMediana(vet, inicio, fim, mediana);
        quickSort(vet,inicio,indicePivo-1);
        quickSort(vet,indicePivo+1,fim);
    }
}
/** manualSort para quando o tamanho do vetor é menor/igual a 3**/
void Sorts::manualSortQuick(int vet[], int inicio, int fim)
{
    int tam = (fim-inicio);

    if(tam == 2)
    {
        addContadorCompara();
        if(vet[inicio] > vet[fim])
        {
            addContadorCompara();
            std::swap(inicio,fim);
            addNumRegistros();
            addNumRegistros();
        }
    }
    else if(tam > 2)
    {
        addContadorCompara();
        int meio = fim-1;
        addNumRegistros();
        if(vet[inicio] > vet[meio])
        {
            addContadorCompara();
            std::swap(inicio,meio);
            addNumRegistros();
            addNumRegistros();
        }
        if(vet[inicio]> vet[fim])
        {
            addContadorCompara();
            std::swap(inicio,fim);
            addNumRegistros();
            addNumRegistros();
        }
        if(vet[meio]> vet[fim])
        {
            addContadorCompara();
            std::swap(meio,fim);
            addNumRegistros();
            addNumRegistros();
        }
    }
}

/** Sort escolhido como "MEUSORT" **/
void Sorts::shellSort(int *vet, int tam)
{
    int i, j, valor;
    int lacuna = 1;
    while(lacuna < tam)
    {
        addContadorCompara();
        lacuna = 3*lacuna+1;
    }
    while ( lacuna > 1)
    {
        addContadorCompara();
        lacuna /= 3;
        for(i = lacuna; i < tam; i++)
        {
            addContadorCompara();
            valor = vet[i];
            addNumRegistros();
            j = i;
            addNumRegistros();
            while (j >= lacuna && valor < vet[j - lacuna])
            {
                addContadorCompara();
                vet[j] = vet [j - lacuna];
                addNumRegistros();
                j = j - lacuna;
                addNumRegistros();
            }
            vet [j] = valor;
            addNumRegistros();
        }
    }
}
void Sorts::imprimeValores()
{
    std::cout << "Numero de comparacoes: " << contadorCompara << std::endl;
    std::cout << "Copias de Registros: " << numRegistros << std::endl;
}
