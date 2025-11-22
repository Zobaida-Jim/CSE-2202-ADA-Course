#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int> coin, int v) {
    sort(coin.begin(), coin.end());

    int ans = 0;
    for(int i = coin.size() - 1; i >= 0 && v > 0; i--) {
        if(v >= coin[i]) {
            ans += v / coin[i];
            v = v % coin[i];
        }
    }
    
    return ans;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int v = 590;

    cout << coinChange(coins, v) << endl;
}