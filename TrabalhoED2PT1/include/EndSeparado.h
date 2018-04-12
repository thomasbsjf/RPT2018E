#ifndef ENDSEPARADO_H
#define ENDSEPARADO_H
#include <list>
using namespace std;
class EndSeparado
{
public:
    EndSeparado(int b);
    virtual ~EndSeparado();
    int funcaoHashDivisao(int chave){ return(chave % tamHash); }
    void insere(int chave);
    void mostraHash();

private:
    list<int> *listaHash;
    int tamHash;
};

#endif // ENDSEPARADO_H
