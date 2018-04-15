#include "ListaQuestions.h"
#include <iostream>
#include "Questions.h"
using namespace std;
ListaQuestions::ListaQuestions()
{
    primeiro=NULL;
}
ListaQuestions::~ListaQuestions()
{

    Questions *p = primeiro;
    while(p != NULL)
    {
        Questions *t = p->getProx();
        delete p;
        p = t;
    }

}

Questions* ListaQuestions::insere(string id2, string user2,string data1,string score1,string title1)
{
    Questions *p= new Questions();
    p->setid(id2);
    p->setUser(user2);
    p->setdata(data1);
    p->setscore(score1);
    p->settitle(title1);
    if(primeiro==NULL)
    {
        primeiro=p;
    }
    else
    {
        p->setProx(primeiro);
        primeiro=p;
        return p;
    }
}

bool ListaQuestions::busca(string s)
{
Questions *p;
p=primeiro;
    while (p!=NULL)
    {
        if(s==p->getid())
        {
            p->adiciona();
            return 1;
        }

        p=p->getProx();
    }
    return 0;
}
void ListaQuestions::imprime()
{
    Questions *p;
    p=primeiro;
    while(p!=NULL)
    {
        cout<<" Id          " <<p->getid()<< "               USER          " << p->getid()<<endl;
        p=p->getProx();
    }
}

Questions* ListaQuestions::retornaPrimeiro()
{
    return primeiro;
}
