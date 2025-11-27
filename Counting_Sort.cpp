#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> countSort(vector<int> &a) {
    int n = a.size();
    int maxV = 0;

    // Finding the maximum value
    for(int i = 0; i < n; i++) {
        maxV = max(maxV, a[i]);
    }

    // Create count Array and find the freequency for every element
    vector<int> count(maxV + 1, 0);
    for(int i = 0; i < n; i++) {
        count[a[i]]++;
    }

    // Compute prefix Sum
    for(int i = 1; i <= maxV; i++) {
        count[i] += count[i - 1];
    }

    // Build output array
    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i--) {
        ans[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    return ans;
}

int main() {
    vector<int> a = {4, 1, 3, 4, 3};

    vector<int> ans = countSort(a);

    for(int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}