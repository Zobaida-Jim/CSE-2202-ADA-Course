#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack_Recursion(vector<int> val, vector<int> wt, int W, int n) { // O(2^n)
    if(n == 0 || W == 0) {
        return 0;
    }

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];
    if(itemWt <= W) {
        //include
        int ans1 = knapsack_Recursion(val, wt, W-itemWt, n-1) + itemVal;
        
        //exclude
        int ans2 = knapsack_Recursion(val, wt, W, n - 1);

        return max(ans1, ans2);
    }
    else {
        // exclude
        return knapsack_Recursion(val, wt, W, n - 1);
    }
}

int knapsack_Memoization(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>> &dp) { // O(n * w)
    if(n == 0 || W == 0) {
        return 0;
    }

    if(dp[n][W] != -1) {
        return dp[n][W];
    }

    int itemWt = wt[n - 1];
    int itemVal = val[n - 1];
    if(itemWt <= W) {
        //include
        int ans1 = knapsack_Memoization(val, wt, W-itemWt, n-1, dp) + itemVal;
        
        //exclude
        int ans2 = knapsack_Memoization(val, wt, W, n - 1, dp);

        dp[n][W] = max(ans1, ans2);
    }
    else {
        // exclude
        dp[n][W] = knapsack_Recursion(val, wt, W, n - 1);
    }
    return dp[n][W];
}

int knapsack_Tabulation(vector<int> val, vector<int> wt, int w, int n) { //O(n*w)
    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

    for(int i = 1; i < n+1; i++) { // i = number of item not index
        for(int j = 1; j < w+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];
            if(itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]); // include
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][w];
}

int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;
    cout << "Recursion : " << knapsack_Recursion(val, wt, W, n) << endl;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout << "Memoization : " << knapsack_Memoization(val, wt, W, n, dp) << endl;

    cout<< "Tabulation : " << knapsack_Tabulation(val, wt, W, n) << endl;
}