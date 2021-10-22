
using namespace std;
#include <iostream>

typedef struct {
    double x;
    double y;
}tocka;

typedef struct {
    tocka l;
    tocka r;
}pravokutnik;

typedef struct {
    tocka s;
    double r;
}kruznica;



int main()
{
    kruznica* niz;
    niz[0].s.x = 10;
    std::cout << "Hello World!\n";
}

