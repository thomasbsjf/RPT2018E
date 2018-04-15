#ifndef LISTAQUESTIONS_H
#define LISTAQUESTIONS_H
#include <iostream>
#include "Questions.h"
using namespace std;

class ListaQuestions
{
    public:
        ListaQuestions();
        virtual ~ListaQuestions();

void setuser(string s)
{

}

Questions* insere(string id2, string user2,string data1,string score1,string title1);
bool busca(string id);
void imprime();
Questions * retornaPrimeiro();

    protected:

    private:
    Questions *primeiro;



};


#endif // LISTAQUESTIONS_H
