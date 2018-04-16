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
/** Retorna o numero de colisoes**/
int EndAberto::getContadorColisao()
{
    return contadorColisao;
}
/** Adiciona mais uma colisao**/
void EndAberto::setContadorColisao()
{
    contadorColisao++;
}
/** Retorna tamanho do hash, usado pra criar o vetor**/
int EndAberto::getTamanhoHash()
{
    return tamHash;
}

void EndAberto::setTamanhoHash(int tam)
{
    tamHash = tam;
}
/** Inicializa o vetor com -1 em todos campos vazios**/
void EndAberto::inicializaVetor()
{
    v   = new int[getTamanhoHash()];
    for(int i=0; i< getTamanhoHash(); i++)
    {
        v[i] = -1;
    }
}
/** Hash por divisao **/
int EndAberto::funcaoHashDivisao(int chave)
{
    return (chave % getTamanhoHash());
}


/** Insere tratando por Sondagem Linear **/
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
/** Insere tratando por Sondagem Quadratica**/
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
/** Insere tratando por Hash Duplo**/
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
/** Pesquisa um certo valor no vetor hash**/
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
/** Tratamento por Sondagem Linear**/
int EndAberto::SondagemLinear(int pos, int i)
{
    return ((pos + i) % getTamanhoHash());
}
/** Tratamento por Sondagem Quadratica**/
int EndAberto::SondagemQuadratica(int pos, int i)
{
    pos = pos + 1*i + 1*i*i;
    return (pos % getTamanhoHash());
}
/** Tratamento por Duplo Hash**/
int EndAberto::SondagemDuploHash(int h1, int chave, int i)
{
    int h2 = (chave % getTamanhoHash()-1) + 1;
    return ((h1 + i*h2) % getTamanhoHash());
}





