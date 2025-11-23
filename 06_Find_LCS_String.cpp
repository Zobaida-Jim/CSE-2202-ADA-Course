#include<iostream>
#include<vector>
#include<string>
using namespace std;

void lcs(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < m+1; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << "Maximum length : " << dp[n][m] << endl;

    string s = "";
    for(int i = n, j = m; i > 0 && j > 0;) {
        if(s1[i-1] == s2[j-1]) {
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main() {
    string s1, s2;
    cout << "Enter String s1 : "; 
    cin >> s1;
    cout << "Enter string s2 : "; 
    cin >> s2;

    lcs(s1, s2);
}