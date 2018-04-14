#include <iostream>
#include <EndAberto.h>
#include <EndSeparado.h>
#include <Sorts.h>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

int main()
{



    cout << "Testes!" << endl;

    int c[] = {28, 11, 21, 8, 12};
    int b1[] = {28, 11, 27, 8, 12, 9, 7, 6, 5, 4, 28, 11, 27, 8, 12, 9, 7, 6, 5, 4, 28, 11, 27, 8, 12, 9, 7, 6, 5, 4};
    cout << "Testes!1" << endl;
    Sorts *a = new Sorts();
    a->quickSortMediana(c,0,5);
    for(int i = 0; i< 5; i++){
        cout << c[i]<< " ";
    }
    cout << endl;
    cout << "Testes!2" << endl;
    cout << "Testes3!" << endl;

}
