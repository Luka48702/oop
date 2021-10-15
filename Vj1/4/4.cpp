
#include <iostream>
using namespace std;


int min(int* arr, int n) {
    int i;
    int* min_n = new int(*arr);
    for (i = 0; i < n; i++) {
        if (*(arr + i) < *min_n) {
            *min_n = *(arr + i);
        }
    }

    return *min_n;
}

int max(int* arr, int n) {
    int i;
    int *max_n = new int(0);
    for (i = 0; i < n; i++) {
        if (*(arr + i) > *max_n) {
            *max_n = *(arr + i);
        }
    }

    return *max_n;
}

int *upis(int* arr, int n) {
    int i = 0;
    for (i; i < n; i++) {
        cout << "Unesite element niza: ";
        cin >> *(arr + i);
    }
    return arr;
}

int main()
{
    //int arr[] = {12,5,1,612,613,0,1,56,9,12};
    //int n = sizeof(arr) / sizeof(arr[0]);
    int n;
    cout << "Unesite duljinu niza: ";
    cin >> n;
    int* arr = new int[n];
    upis(arr, n);
    cout << "Minimum element of array is: " << min(arr, n) << "\n";
    cout << "Maximum element of array is: " << max(arr, n) << "\n";
    return 0;
}

