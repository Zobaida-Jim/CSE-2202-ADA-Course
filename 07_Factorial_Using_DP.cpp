#include<iostream>
#include<vector>
using namespace std;

int memorization(int n, vector<int> &f) {
    if(n == 0 || n == 1) {
        return 1;
    }
    if(f[n] != 0) {
        return f[n];
    }
    f[n] = n * memorization(n - 1, f);
    return f[n];
}

int tabulation(int n) {
    vector<int> f(n + 1, 0);
    f[0] = 1;
    f[1] = 1;

    for(int i = 2; i <= n; i++) {
        f[i] = i * f[i - 1];
    }
    return f[n];
}

int main() {
    int n;
    cin >> n;

    vector<int> f(n + 1, 0);
    cout << memorization(n, f) << endl;

    cout << tabulation(n) << endl;
}