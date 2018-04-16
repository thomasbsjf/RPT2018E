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

    Questions* insere(string id2, string user2,string data1,string score1,string title1);
    bool busca(string id);
    void imprime();
    Questions * getPrimeiro(){return primeiro;}

private:
    Questions *primeiro;

};

#endif // LISTAQUESTIONS_H
