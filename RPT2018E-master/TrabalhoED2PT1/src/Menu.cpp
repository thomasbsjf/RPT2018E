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
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
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
{   cout<< "\n Digite o cenario desejado numerados de 1 a 4 \n"<<endl;
    int x=0;
cout<<" CENARIO 1 : Impacto de diferentes estruturas de dados.\n CENARIO 2 : Impactos da variação de QuickSort \n CENARIO 3 : Quicksort X InsertionSort X Mergesort X Heapsort X Meusort \n CENARIO 4 Tratamento de Colisões: Endereçamento X Encadeamento \n"<<endl;
    while(x<1||x>4)
    {   cin>>x;
        switch(x)
        {
        case 1 :

           Cenario1(50000);
           //checaDesempenho(1000);
            break;
        case 2 :
            return 2;
            break;
        case 3 :
            return 3;
            break;
        case 4 :
            return 4;
            break;
        default :
            {
                cout<<"\n Valor digitado INVALIDO, digite novamente um valor valido entre 1 e 4."<<endl;
            }

        }

    }
    return x;
}


Menu::~Menu()
{
    //dtor
}

void Menu::Cenario1(int n)
{
    Questions *Q= new Questions [n];
    criaVetorQuestions(n,Q);
    v=new int [n];
    int *V= new int [n];
    for(int i=0;i<n;i++)
    {
        cout<<"   " << Q[i].getId();
    V[i]=Q[Rand(n)].getId();
    }
    Sorts s;
     clock_t inic, fin;
    inic = clock();

    s.quickSort(V,0,n);
    fin = clock();
 std::ofstream saida;
    saida.open("saida.txt", std::ios::app);
    if(saida.is_open())
     {
        saida << "Tempo de execucao: " << (fin - inic) / CLOCKS_PER_SEC << "\n\n";
        saida << "--------------------//-------------------- \n\n";
    }
    else
    {
        cout << "Erro ao abrir arquivo saida.txt";
    }
    cout<< (fin - inic) / CLOCKS_PER_SEC <<endl;
    saida.close();

}

void Menu::checaDesempenho(int n)
{   Sorts s;
    clock_t inic, fin;
    inic = clock();

    fin = clock();
    v=NULL;
    //cout << "Tempo de execucao: " << (fin - inic) / CLOCKS_PER_SEC;
    std::ofstream saida;
    saida.open("saida.txt", std::ios::app);
    if(saida.is_open())
    {
        saida << "Tempo de execucao: " << (fin - inic) / CLOCKS_PER_SEC << "\n\n";
        saida << "--------------------//-------------------- \n\n";
    }
    else
    {
        cout << "Erro ao abrir arquivo saida.txt";
    }
    cout<< (fin - inic) / CLOCKS_PER_SEC <<endl;
    saida.close();
}
int Menu::Rand(int n)
{
    srand((unsigned)time(0)); //para gerar números aleatórios reais.
      int aleatorio = rand()%n;
      return aleatorio;
}

void Menu::criaVetorQuestions(int N,Questions * Q)
{
    ifstream questions;
    string s;
    char c;
    int i=0;
    Questions *q;
    string id,user,data,score,title;

    int x=0;
    questions.open("Questions2.txt");
    if(questions.is_open()) // CONFERE SE O ARQUIVO FOI ABERTO,
    {
        while(i<N)
        {

            questions.get(c);
            if(c== '*') // CHECA A EXISTENCIA DA VIRGULA
            {

                getline(questions,id);
            stringstream ss(id);
                ss>>x;

            }
            if(c=='-')
            {
                getline(questions,user);

            }
            if(c=='@')

            {

                getline(questions,data);

            }
            if(c=='%')
            {
                getline(questions,score);


            }
            if(c=='#')
            {
                getline(questions,title);

            }
            if(title!="null")
            {
                q=new Questions(x,user,data,score,title) ;

            }
            Q[i]=*q;
            title="null";

            i++;


        }

        if(Q==NULL)
            cout<< "NULL"<<endl;
        }
           questions.close();
    }
