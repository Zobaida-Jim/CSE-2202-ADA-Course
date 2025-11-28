#include<iostream>
#include<vector>
#include<string>
using namespace std;

int lcs_Recursion(string str1, string str2) { // O(2^(n+m))
    int n = str1.size();
    int m = str2.size();
    if(n == 0 || m == 0) {
        return 0;
    }
    if(str1[n-1] == str2[n-1]) {
        return 1 + lcs_Recursion(str1.substr(0, n - 1), str2.substr(0, m - 1));
    }
    else {
        int ans1 = lcs_Recursion(str1.substr(0, n - 1), str2);
        int ans2 = lcs_Recursion(str1, str2.substr(0, m - 1));
        return max(ans1, ans2);
    }
}

int lcs_Memoization(string str1, string str2, vector<vector<int>> dp) { // O(n * m)
    int n = str1.size();
    int m = str2.size();
    if(n == 0 || m == 0) {
        return 0;
    }
    if(dp[n][m] != -1) {
        return dp[n][m];
    }
    if(str1[n-1] == str2[n-1]) {
        dp[n][m] = 1 + lcs_Memoization(str1.substr(0, n - 1), str2.substr(0, m - 1), dp);
    }
    else {
        int ans1 = lcs_Memoization(str1.substr(0, n - 1), str2, dp);
        int ans2 = lcs_Memoization(str1, str2.substr(0, m - 1), dp);
        dp[n][m] = max(ans1, ans2);
    }
    return dp[n][m];
}

int lcs_Tabulation(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <n+1; i++) {
        for(int j = 1; j < m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string str1 = "abcdge";
    string str2 = "abedg";

    cout << "Recursion : " << lcs_Recursion(str1, str2) << endl;

    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m+1, -1));
    cout << "Memoization : " << lcs_Memoization(str1, str2, dp) << endl;

    cout << "Tabulation : " << lcs_Tabulation(str1, str2) << endl;
}