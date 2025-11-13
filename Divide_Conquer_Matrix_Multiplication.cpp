#include<iostream>
#include<vector>
using namespace std;
using matrix = vector<vector<int>>;

matrix add(const matrix &A, const matrix &B) {
    int n = A.size();
    matrix c(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            c[i][j] = A[i][j] + B[i][j];
        }
    }
    return c;
}

matrix multiply(const matrix &A, const matrix &B) {
    int n = A.size();
    if(n == 1) {
        return {{A[0][0] * B[0][0]}};
    }
    int mid = n / 2;
    matrix A11(mid, vector<int>(mid));
    matrix A12(mid, vector<int>(mid));
    matrix A21(mid, vector<int>(mid));
    matrix A22(mid, vector<int>(mid));
    matrix B11(mid, vector<int>(mid));
    matrix B12(mid, vector<int>(mid));
    matrix B21(mid, vector<int>(mid));
    matrix B22(mid, vector<int>(mid));
    for(int i = 0; i < mid; i++) {
        for(int j = 0; j < mid; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }
    matrix c11 = add(multiply(A11, B11), multiply(A12, B21));
    matrix c12 = add(multiply(A11, B12), multiply(A12, B22));
    matrix c21 = add(multiply(A21, B11), multiply(A22, B21));
    matrix c22 = add(multiply(A21, B12), multiply(A22, B22));

    matrix c(n, vector<int>(n));
    for(int i = 0; i < mid; i++) {
        for(int j = 0; j < mid; j++) {
            c[i][j] = c11[i][j];
            c[i][j + mid] = c12[i][j];
            c[i + mid][j] = c21[i][j];
            c[i + mid][j + mid] = c22[i][j];
        }
    }
    return c;
}

int main() {
    int n; 
    cout << "Enter matrix size (power of 2) : ";
    cin >> n;
    matrix A(n, vector<int>(n));
    matrix B(n, vector<int>(n));
    cout << "Enter matrix A : ";
    for(auto &row : A) {
        for(int &x : row) {
            cin >> x;
        }
    }
    cout << "Enter matrix B : ";
    for(auto &row : B) {
        for(int &x : row) {
            cin >> x;
        }
    }
    matrix C = multiply(A, B);
    cout << "Final Matrix " << endl;
    for(auto &row : C) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}