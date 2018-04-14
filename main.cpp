#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "ListaQuestions.h"
#include "Questions.h"
using namespace std;


int main()
{
    ifstream questions;
    ifstream cags;   // ABRE MODO LEITURA
    questions.open("Questions2.txt");
    string s;
    char c;
    int i=0;
Questions *q;
    string id,user,data,score,title;

    ListaQuestions t;

    int n=0;
    cout<<" DIGITE O N "<<endl;
    int N=1000;
    cin>> N;
    Questions Q[N],a;
    if(questions.is_open()) // CONFERE SE O ARQUIVO FOI ABERTO,
    {
        while(i<1000)
        {

            questions.get(c);
            if(c== '*') // CHECA A EXISTENCIA DA VIRGULA
            {
                getline(questions,id);
                a.setid(id);
            }
            if(c=='-')
            {
                getline(questions,user);
                a.setUser(user);
            }
            if(c=='@')

            {

                getline(questions,data);
                a.setdata(data);
            }
            if(c=='%')
            {
                getline(questions,score);
                a.setscore(score);

            }
            if(c=='#')
            {
                getline(questions,title);
                a.settitle(title);
            }
            if(title!="null")
            {
                q=new Questions(id,user,data,score,title) ;

            }
            Q[i]=*q;
            title="null";

    i++;
             cout<<".."<<endl;

        }
        int n=1;
    if(Q==NULL)
        cout<< "NULL"<<endl;


        while(n!=0)
        {
            cout<<" DIGITE INDICE " <<endl;
            cin>>n;

           Q[n].imprime();
        }
    }
    questions.close();
}
//t.imprime();

// IMPLEMENTAR FECHAR ARQUIVO;

/**<  srand(time(NULL))
{

    for(int =0;i<N;i++)
    {

        int g=rand()%N
     v[g]=0
    }
}
}

*/
