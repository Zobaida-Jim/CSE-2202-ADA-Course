/// Recursion - Memoization - Tabulation

#include<iostream>
#include<vector>
using namespace std;

int ways_recursion(int n) {
    if(n == 0 || n == 1) {
        return 1;
    }
    return ways_recursion(n - 1) + ways_recursion(n - 2);
}

int ways_memoiozation(int n, vector<int> &dp) { // O(n)
    if(n == 0 || n == 1) {
        return 1;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    dp[n] = ways_memoiozation(n - 1, dp) + ways_memoiozation(n - 2, dp);
    return dp[n];
}

int ways_tabulation(int n) { // O(n)
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the number of Stairs : ";
    cin >> n;
    cout << "Recursion : " << ways_recursion(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Memoization : " << ways_memoiozation(n, dp) << endl;

    cout << "Tabulation : " << ways_tabulation(n) << endl;
}