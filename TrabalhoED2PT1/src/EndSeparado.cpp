#include "EndSeparado.h"
#include <list>
#include <iostream>
using namespace std;
EndSeparado::EndSeparado(int b)
{
    this->tamHash = b;
    listaHash = new list<int>[tamHash];
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
        for (list<int>::iterator i = listaHash->begin(); i!= listaHash->end(); ++i)
        {
            cout << " --> " + *i << endl;
        }
    }
}
