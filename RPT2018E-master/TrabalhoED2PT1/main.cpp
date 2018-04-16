#include <iostream>
#include <fstream>
#include <EndAberto.h>
#include <EndSeparado.h>
#include <Sorts.h>
#include <time.h>
#include <stdlib.h>
#include "ListaQuestions.h"
#include "Questions.h"
#include "Menu.h"
using namespace std;

int main()
{
    int vet[7];
    ifstream parametros ("parametros.txt");
    if (parametros.is_open())
    {
        int n = 0;
        int i = 0;
        while (parametros >> n)
        {
            vet[i] = n;
            i++;
        }
        parametros.close();
    }
    else
        cout << "Nao foi possivel abrir o arquivo.";
Menu m;
m.Cenarios();
    return 0;
}

