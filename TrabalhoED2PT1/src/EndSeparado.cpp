#include "EndSeparado.h"
#include <vector>
#include <iostream>
using namespace std;
EndSeparado::EndSeparado(int b)
{
    this->tamHash = b;
    listaHash = new vector<int>[tamHash];
}

EndSeparado::~EndSeparado()
{

}

void EndSeparado::insere(int chave)
{
    int i = funcaoHashDivisao(chave);
    listaHash[i].push_back(chave);
}

void EndSeparado::mostraHash()
{
    for (int i = 0; i < tamHash; i++)
    {
        cout << i;
        for(auto x : listaHash[i])
        {
            cout << " --> " << x;
        }
        cout << endl;
    }
}
