#ifndef ENDABERTO_H
#define ENDABERTO_H


class EndAberto
{
    public:
        EndAberto();
        virtual ~EndAberto();

        void inicializaVetor();
        int funcaoHashDivisao(int chave);
        int SondagemLinear(int pos, int i);
        int SondagemQuadratica(int pos, int i);
        int SondagemDuploHash(int pos, int i, int n);
        int inserirLinear(int n);
        int inserirQuadratico(int n);
        int inserirDuplo(int n);
        int pesquisar(int n);
    
        int getTamanhoHash();
        void setTamanhoHash(int tam);
        int getContadorColisao();
        void setContadorColisao(int n);

    private:
        int tamHash;
        int *v;
        int contadorColisao;
};

#endif // ENDABERTO_H
