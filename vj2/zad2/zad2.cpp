#include <iostream>
using namespace std;


void povratnaVrijednost(int niz[], int i, int &pov)
{
    pov = niz[i - 1];
}

int main()
{
    int niz[] = {2, 4, 6, 8, 10};
    int i = 1;
    int pov;

    povratnaVrijednost(niz, i, pov);

    cout << "Vrijednost je: " << pov + 1;
}

