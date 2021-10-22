#include <iostream>
using namespace std;

struct matrica
{
    float* broj;
    void unos();
    void ispis();
};

void matrica::unos() {
    cin.ignore();
    cout << "Unesite broj." << endl;
    broj = new float;
    cin >> *(broj);
}

void matrica::ispis() {

    cout << " " << *broj << " ";

}

void unos2dniza(matrica** niz, int vel, int vel2) {
    for (int i = 0; i < vel; i++)
    {
        for (int j = 0; j < vel2; j++)
        {
            (*(niz + i) + j)->unos();
        }
    }
}

void ispis2dniza(matrica** niz, int vel, int vel2) {

    for (int i = 0; i < vel; i++)
    {
        for (int j = 0; j < vel2; j++)
        {
            (*(niz + i) + j)->ispis();
        }
        cout << endl;
    }

}

int main()
{
    int vel, vel2;
    do
    {
        cout << "Unesite dimenzije 2d niza." << endl;
        cin >> vel;
        cin >> vel2;

    } while (vel < 0 || vel2 < 0);

    matrica** niz = new matrica * [vel];
    for (int i = 0; i < vel; i++)
    {
        *(niz + i) = new matrica[vel2];
    }
    unos2dniza(niz, vel, vel2);
    cout << endl << "Ispis 2d niza: " << endl;
    ispis2dniza(niz, vel, vel2);

    for (int i = 0; i < vel; i++)
    {
        delete[] * (niz + i);
        *(niz + i) = nullptr;
    }

    delete[]niz;
    niz = nullptr;

    system("pause");
    return 0;
}