// Zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int min(int *A, int n, int small){
    if (n < 0) {
        return small;
    }
    else {
        if (*A < small) {
            small = *A;
        }
        return min(++A, --n, small);
    }
}

int max(int* A, int n, int maximall) {
    if (n < 0) {
        return maximall;
    }
    else {
        if (*A > maximall) {
            maximall = *A;
        }
        return max(++A, --n, maximall);
    }
}

int* input(int *A, int n) {
    int i = 0;
    for (i; i < n; i++) {
        cout << "Unesite element niza: ";
        cin >> *(A+i);
    }
    return A;
}

int main()
{
    //int A[] = { 1, 4, 45, 6, -50, 10, 2 };
    //int n = sizeof(A) / sizeof(A[0]);
    int n;
    cout << "Unesite duljinu niza: ";
    cin >> n;
    int *A = new int[n];
    input(A, n);
    cout << "Minimum element of array is: " << min(A, n - 1, *A) << "\n";
    cout << "Maximum element of array is: " << max(A, n - 1, *A) << "\n";
    return 0;
}

