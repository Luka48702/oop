using namespace std;
#include <iostream>

typedef struct {
    double x;
    double y;
}tocka;

typedef struct {
    tocka a;
    tocka b;
}pravokutnik;

typedef struct {
    tocka s;
    double r;
}kruznica;

void unosKruznice(kruznica* k) {
    cout << "unesite kruznicu: \n";
        cout << "r: ";
    cin >> k->r;
    cout << "sx: ";
    cin >> k->s.x;
    cout << "sy:";
    cin >> k->s.y;
}

void unosPravokutnika(pravokutnik* arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        cout << "Unesite pravokutnik[" << i + 1 << "]\n";
        cout << "ax:";
        cin >> arr[i].a.x;
        cout << "ay:";
        cin >> arr[i].a.y;
        cout << "bx:";
        cin >> arr[i].b.x;
        cout << "by:";
        cin >> arr[i].b.y;
    }
}

int presjek(kruznica& k, pravokutnik* arr, int n) {
    tocka P;
    int br = 0;
    for (int i = 0; i < n; i++) {
        P.x = k.s.x - max(arr[i].a.x, min(k.s.x, arr[i].a.x + (arr[i].b.x - arr[i].a.x)));
        P.y = k.s.y = max(arr[i].a.y, min(k.s.y, arr[i].a.y + (arr[i].b.y - arr[i].a.y)));

        if ((P.x * P.x + P.y * P.y) <= k.r * k.r) {
            br++;
        }

    }
    return br;
}

int main()
{
    int br;
    int n;
    cout << "Unesite broj pravokutnika: ";
    cin >> n;
    pravokutnik* arr;
    kruznica k;
    arr = new pravokutnik[n];
    unosPravokutnika(arr, n);
    unosKruznice(&k);
    br = presjek(k, arr, n);
    cout << "\n" << br << " pravoukutnik/a sjece kruznicu";
}

