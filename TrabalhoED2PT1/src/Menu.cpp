#include "Menu.h"
#include <cstdlib>
#include <iostream>
using namespace std;
Menu::Menu()
{
    system("color 06");
    system("title ESTRUTURA DE DADOS TRABALHO 1");
    cout<<" UNIVERSIDADE FEDERAL DE JUIZ DE FORA \n Departamento de Ciencia da Computacao – 2018.1 \n DCC012 _ Estruturas de Dados II _ Trabalho 1"<<endl;
    cout<<" Desenvolvido por : Thomas Santos, Pedro Henrique Eveling e Rafael Braga \n\n\n "<<endl;

    system("PAUSE");

}

int Menu::Cenarios()
{   cout<< "\n Digite o cenario desejado numerados de 1 a 6 \n"<<endl;
    int x=0;
cout<<" 1 : N = 1k \n 2 : N = 5k \n 3 : N = 10k \n 4 : N = 50k \n 5 : N = 100k \n 6 : N = 500k \n"<<endl;
    while(x<1||x>6)
    {   cin>>x;
        switch(x)
        {
        case 1 :
            return 1000;
            break;
        case 2 :
            return 5000;
            break;
        case 3 :
            return 10000;
            break;
        case 4 :
            return 50000;
            break;
        case 5 :
            return 100000;
            break;
        case 6 :
            return 500000;
            break;
        default :
            {
                cout<<"\n Valor digitado INVALIDO, digite novamente um valor valido entre 1 e 6."<<endl;
            }

        }

    }
    return x;
}


Menu::~Menu()
{
    //dtor
}
