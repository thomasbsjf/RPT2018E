#include "Questions.h"

Questions::Questions()
{
    //ctor
}

Questions::Questions(string id1, string user1,string data1,string score1,string title1)
{
    id = id1;
    user = user1;
    data = data1;
    score = score1;
    title = title1;
}
Questions::~Questions()
{
    //dtor
}

void Questions::imprime()
{
    cout<< id<<endl;
    cout<< user<<endl;
    cout<<title<<endl;
}

void Questions::compara(string s)
{
    if(id==s)
    {
        setQtd();
    }
}
