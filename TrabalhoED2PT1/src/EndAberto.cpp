#include "EndAberto.h"
#include <ostream>
#include <iostream>
using namespace std;
EndAberto::EndAberto()
{
    tamHash = 0;
    setContadorColisao(0);
}

EndAberto::~EndAberto()
{

}

int EndAberto::getTamanhoHash()
{
    return tamHash;
}

void EndAberto::setTamanhoHash(int tam)
{
    tamHash = tam;
}

void EndAberto::inicializaVetor()
{
    v   = new int[getTamanhoHash()];
    for(int i=0; i< getTamanhoHash(); i++)
    {
        v[i] = -1;
    }
}

int EndAberto::funcaoHashDivisao(int chave)
{
    return (chave % getTamanhoHash());
}



int EndAberto::inserirLinear(int n)
{
    int pos = funcaoHashDivisao(n);
    if(v[pos] != -1)
    {
        for(int i = 1 ; i < getTamanhoHash(); i++)
        {
            int newPos = SondagemLinear(pos,i);
            if(v[newPos] == -1)
            {
                v[newPos] = n;
                setContadorColisao(i);
                return 1;
            }
        }
    }

    v[pos] = n;
    return 0;
}

int EndAberto::inserirQuadratico(int n)
{
    int pos = funcaoHashDivisao(n);

    if(v[pos] != -1)
    {
        for(int i=1; i < getTamanhoHash(); i++)
        {
            int newPos = SondagemQuadratica(pos, i);
            if(v[newPos] == -1)
            {
                v[newPos] = n;
                setContadorColisao(i);
                return 1;
            }
        }
    }

    v[pos] = n;
    return 0;
}

int EndAberto::inserirDuplo(int n)
{
    int pos = funcaoHashDivisao(n);
    if(v[pos] != -1)
    {
        for(int i=1; i< getTamanhoHash(); i++)
        {


            int newpos = SondagemDuploHash(pos, i, n);
            if(newpos != pos)
            {
                v[newpos] = n;
                setContadorColisao(i);
            }
        }
    }

    v[pos]= n;
    return 0;
}

int EndAberto::pesquisar(int n)
{
    int pos = funcaoHashDivisao(n);
    while(v[pos] != -1)
    {
        if(v[pos] == n)
        {
            return pos;
        }
        pos++;
    }
    return 0;
}

int EndAberto::SondagemLinear(int pos, int i)
{
    return ((pos + i) % getTamanhoHash());
}

int EndAberto::SondagemQuadratica(int pos, int i)
{
    pos = pos + 1*i + 1*i*i;
    return (pos % getTamanhoHash());
}

int EndAberto::SondagemDuploHash(int h1, int chave, int i)
{
    int h2 = (chave % getTamanhoHash()-1) + 1;
    return ((h1 + i*h2) % getTamanhoHash());
}





