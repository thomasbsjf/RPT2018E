#ifndef ENDCOALESCIDO_H
#define ENDCOALESCIDO_H

struct Balde {
       bool usado;
       char chave;
       long valor;
	   short proximo;
};


class EndCoalescido
{
    public:
        EndCoalescido();
        virtual ~EndCoalescido();
        void insere(int chave);

    private:
};

#endif // ENDCOALESCIDO_H
