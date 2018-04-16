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
/** Utiliza um Vector, faz o Hash, Insere no fim da lista **/
void EndSeparado::insere(int chave)
{
    int i = funcaoHashDivisao(chave);
    listaHash[i].push_back(chave);
}
/** Funcao para testar se estar inserindo**/
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
