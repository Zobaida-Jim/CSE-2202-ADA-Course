#include <iostream>
#include <vector>
using namespace std;
void floydWarshall(vector<vector<int>> &dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) { // Intermediate Node
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j]!= INT_MAX)
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    vector<vector<int>> dist = {
        {0, 4, INT_MAX, 5, INT_MAX},
        {INT_MAX, 0, 1, INT_MAX, 6},
        {2, INT_MAX, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 1, 0, 2},
        {1, INT_MAX, INT_MAX, 4, 0}
    };

    floydWarshall(dist);
    for(int i = 0; i<dist.size(); i++) {
        for(int j = 0; j<dist.size(); j++) {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}