#include <iostream>
#include<vector>
using namespace std;

int n;
vector<vector<int>> cost;
vector<bool> visited;

int solve(int pos, int count) {
    // If all cities visited, return to starting city
    if (count == n) {
        return cost[pos][0];
    }
    
    int minCost = INT_MAX;
    
    // Try all unvisited cities
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            minCost = min(minCost, cost[pos][i] + solve(i, count + 1));
            visited[i] = false;  // Backtrack
        }
    }
    
    return minCost;
}

int main() {
    cost = {{0, 10, 15, 20}, 
            {10, 0, 35, 25}, 
            {15, 35, 0, 30}, 
            {20, 25, 30, 0}};
    
    n = cost.size();
    visited.resize(n, false);
    visited[0] = true;  // Start from city 0
    
    cout << solve(0, 1) << endl;
    return 0;
}