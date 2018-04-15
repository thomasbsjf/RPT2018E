#ifndef ENDSEPARADO_H
#define ENDSEPARADO_H
#include <vector>
using namespace std;
class EndSeparado
{
public:
    EndSeparado(int b);
    virtual ~EndSeparado();
    int funcaoHashDivisao(int chave)
    {
        return(chave % tamHash);
    }
    void insere(int chave);
    void mostraHash();

private:
    vector<int> *listaHash;
    int tamHash;
};

#endif // ENDSEPARADO_H
