#ifndef QUESTIONS_H
#define QUESTIONS_H
#include <iostream>

using namespace std;

class Questions
{
public:
    Questions(); //CONSTRUTOR PARA INICIAR QUANTIDADE =0;
    Questions(string id1, string user1,string data1,string score1,string title1);
    virtual ~Questions();

    string getId(){return id;}
    void setId(string t){id=t;}

    string getData(){return data;}
    void setData(string data1){data=data1;}

    string getScore(){return score;}
    void setScore(string score1){score=score1;}

    string getTitle(){return title;}
    void setTitle(string title1){title=title1;}

    int getUser(){return qtd;} // RETORNA QNT PRIVADO;
    void setUser(string user1){user=user1;}

    Questions* getProx(){return prox;}
    void setProx(Questions *p){prox=p;}

    Questions* getAnt(){return ant;}
    void setAnt(Questions* p){ant=p;}

    void setQtd(){qtd++;}
    int getQtd(){return qtd;}

    void compara(string s);
    void imprime();

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
