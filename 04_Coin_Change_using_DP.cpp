#include<iostream>
#include<vector>
using namespace std;

int combination(vector<int> coin, int amount) {
    int n = coin.size();
    vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));
    for(int i = 0; i < n+1; i++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i < n+1; i++) {
        for(int j = 1; j < amount+1; j++) {
            if(coin[i - 1] <= j) { // valid
                dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}

int main() {
    vector<int> coin = {1, 2, 5};
    int amount = 5;
    cout << combination(coin, amount) << endl;
}