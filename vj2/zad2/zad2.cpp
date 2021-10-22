// zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int& funkcija(int* niz, int index, int v) {
   // if (index > v) {
    //    return NULL;
  //  }

    return niz[index];
}




int main()
{
    int niz[] = { 1,2,3,4,5 };
    int index=2;
    int v = 5;
    funkcija(niz, index, v) += 1;
    for (int i = 0; i < v; i++) {
        cout << niz[i] << endl;
    }
}


