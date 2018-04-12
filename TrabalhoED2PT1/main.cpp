#include <iostream>
#include <EndAberto.h>
#include <EndSeparado.h>

using namespace std;

int main()
{
    cout << "Testes!" << endl;
    int b[] = {15, 11, 27, 8, 12};
    EndSeparado a(5);
    for(int i=0; i < 5; i++){
        a.insere(b[i]);
    }
    a.mostraHash();
}
