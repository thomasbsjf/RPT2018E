#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <iostream>

using namespace std;

class Questions
{
    public:
        Questions(); //CONSTRUTOR PARA INICIAR QUANTIDADE =0;
    Questions(string id1, string user1,string data1,string score1,string title1)
    {
        id=id1;
        user=user1;
        data=data1;
        score=score1;
        title=title1;
    }
    virtual ~Questions();
    string getid(){return id;}
    string getdata(){return data;}
    void setdata(string data1){data=data1;}
    string getscore(){return score;}
    void setscore(string score1){score=score1;}
    string gettitle(){return title;}
    void settitle(string title1){title=title1;}
    void setUser(string user1)
    {
        user=user1;
    }
    void imprime()
    {
        cout<< id<<endl;
        cout<< user<<endl;
        cout<<title<<endl;
    }

   int getUser() // RETORNA QNT PRIVADO;
   {
       return qtd;
   }

   Questions* getProx()
    {
        return prox;
    }
    Questions* getAnt()
    {
        return ant;
    }
   void setProx(Questions *p)
   {
       prox=p;
   }
   void adiciona()
   {
       qtd++;
   }
   void setid(string t)
   {
       id=t;
   }
   void setAnt(Questions* p)
   {
       ant=p;
   }
   void comparar(string s)
   {
       if(id==s)
       {
           adiciona();
       }
   }
   int getqtd()
   {
       return qtd;
   }


    protected:

    private:
        string id;
        string user;
        string data;
        string score;
        string title;
        int qtd;
        Questions *prox;
        Questions *ant;
};

#endif // QUESTIONS_H
