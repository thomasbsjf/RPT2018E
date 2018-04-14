#include <iostream>
#include <EndAberto.h>
#include <EndSeparado.h>
#include <Sorts.h>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;
int main()
{
    int n, i=0;
    int vet[6];
    string linha;
    ifstream parametros ("parametros.txt");
    if (parametros.is_open())
    {
        while (parametros >> n )
        {
            vet[i] = n;
            i++;
        }
        parametros.close();
    }

    else
        cout << "Nao foi possivel abrir o arquivo.";
    return 0;
}
