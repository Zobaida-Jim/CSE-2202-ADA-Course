#include<iostream>
#include<vector>
using namespace std;

int fib_memoization(int n, vector<int> &f) { // O(N)
    if(n == 0 || n == 1) {
        return n;
    }
    if(f[n] != -1) {
        return f[n];
    }
    f[n] = fib_memoization(n - 1, f) + fib_memoization(n - 2, f);
    return f[n];
}

int fib_tabulation(int n) { // TC = O(N)
    vector<int> f(n+1, 0);
    f[0] = 0;
    f[1] = 1;

    for(int i = 2; i <+ n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    return f[n];
}

int main() {
    int n; 
    cout << "Enter the value of n : "; 
    cin >> n;
    vector<int>f(n + 1, -1);
    cout <<"Using Memoization : " << fib_memoization(n, f) << endl;

    cout <<"Using Tebulation : " << fib_tabulation(n) << endl;
}