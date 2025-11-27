#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void countingSort(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> ans(n);
    int count[10] = {0}; // 10 based -> decimal

    // count freequesncy
    for(int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        count[digit]++;
    }

    // find prefix sum
    for(int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    for(int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        ans[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for(int i = 0; i < n; i++) {
        a[i] = ans[i];
    }
}

void redixSort(vector<int> &a) {
    int maxV = *max_element(a.begin(), a.end());

    for(int exp = 1; maxV / exp > 0; exp *= 10) {
        countingSort(a, exp);
    }
}

int main() {
    vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};

    redixSort(a);

    for(int x : a) {
        cout << x << " ";
    }
    cout << endl;
}