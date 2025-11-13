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
matrix subtract(const matrix &A, const matrix &B) {
    int n = A.size();
    matrix c(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            c[i][j] = A[i][j] - B[i][j];
        }
    }
    return c;
}

matrix strassen(const matrix &A, const matrix &B) {
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
    auto M1 = strassen(add(A11, A22), add(B11, B22));
    auto M2 = strassen(add(A21, A22), B11);
    auto M3 = strassen(A11, subtract(B12, B22));
    auto M4 = strassen(A22, subtract(B21, B11));
    auto M5 = strassen(add(A11, A12), B22);
    auto M6 = strassen(subtract(A21, A11), add(B11, B12));
    auto M7 = strassen(subtract(A12, A22), add(B21, B22));
    matrix c(n, vector<int>(n));
    matrix c11 = add(subtract(add(M1, M4), M5), M7);
    matrix c12 = add(M3, M5);
    matrix c21 = add(M2, M4);
    matrix c22 = add(subtract(add(M1, M3), M2), M6);
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
    cout << "Enter the size of the matrix (power of 2) : ";
    cin >> n;
    matrix A(n, vector<int>(n));
    cout << "Enter matrix A : ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    matrix B(n, vector<int>(n));
    cout << "Enter matrix B : ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> B[i][j];
        }
    }
    matrix c = strassen(A, B);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}