// 1zad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void funkcija(int* niz, int& min, int& max, int v) {
    max = niz[0]; // *niz
    min = niz[0];

    int i;
    for (i = 0; i < v; i++) {
        if (niz[i] > max) {
            max = niz[i];
        }

        if (niz[i] < min) {
            min = niz[i];
        }
    }

}

int main()
{
    int min, max;
    int niz[] = { 1, 2, 3, 4, 5 };
    funkcija(niz, min, max, 5);
    cout << min << max;
}


