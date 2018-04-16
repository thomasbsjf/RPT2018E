#ifndef MENU_H
#define MENU_H


class Menu
{
    public:
        Menu();
        virtual ~Menu();
    int Cenarios();
    void criaVetorQuestions(int N,Questions * Q);
    void checaDesempenho(int n);
    void Cenario1(int n);
    int Rand(int n);
    protected:

    private:
        int *v;
};

#endif // MENU_H
