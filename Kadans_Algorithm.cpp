#include<iostream>
#include<vector>
using namespace std;

int kadans(vector<int> &a) { // TC = O(n)
    int n = a.size();

    int maxEnding = a[0];
    int result = a[0];
    for(int i = 1; i < n; i++) {
        maxEnding = max(a[i], maxEnding + a[i]);
        result = max(maxEnding, result);
    }
    return result;
}

int main() {
    vector<int> arr = {3, -1, -7, 8, 2, 9, -2, 6};
    cout << kadans(arr) << endl;
}