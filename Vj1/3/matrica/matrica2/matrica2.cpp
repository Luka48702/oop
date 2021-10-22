
#include <iostream>
#include <iomanip>
#include <stdlib.h> 
#include <time.h> 
using namespace std;
typedef struct {
    int row; 
    int col;
    float** mat; 
}Matrix;

Matrix input(int row, int col)
{
    Matrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.mat = new float* [row];
    for (int i = 0; i < row; i++)
        matrix.mat[i] = new float[col];

    cout << "Enter the elements of matrix 'A'" << endl;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            cin >> matrix.mat[i][j];
        }
    }

    return matrix;

}

void print(Matrix m, int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << m.mat[i][j] << " ";
        }
        cout << endl;
    }

}

Matrix generate(int row, int col)
{
    Matrix matrix;
    srand(time(NULL)); //random
    int a = 1, b = 15;
    Matrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.mat = new float* [row];
    for (int i = 0; i < row; i++) {
        matrix.mat[i] = new float[col];
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            matrix.mat[i][j] = a + (rand() % (b - a + 1));
        }
    }
    return matrix;
}

Matrix add(Matrix mat1, Matrix mat2, int row, int col)
{
    Matrix matrix;
    matrix.row = row;
    matrix.col = col;
    matrix.mat = new float* [row];
    for (int i = 0; i < row; i++) {
        matrix.mat[i] = new float[col];
    }

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix.mat[i][j] = (mat1.mat[i][j] + mat2.mat[i][j]);
        }
    }
    return matrix;
}

Matrix transpose(Matrix m, int row, int col) {
    Matrix matrix;
    matrix.row = col;
    matrix.col = row;
    matrix.mat = new float* [col];
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix.mat[j][i] = m.mat[i][j];
        }
    }
    return matrix;
}

int main()
{
    int m, n;
    cout << "Dimensions of m matrix: " << endl;
    cin >> m;
    cout << "Dimensions of n matrix: " << endl;
    cin >> n;
    Matrix A = input(m, n);
    print(A, m, n);
    cout << endl;
    cout << " " << generate << " ";
    cout << " " << transpose << " ";
    cout << " " << add << " ";
}

