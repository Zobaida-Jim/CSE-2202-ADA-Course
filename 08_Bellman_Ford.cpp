#include<iostream>
#include<vector>
using namespace std;

class Edge {
public:
    int V;
    int wt;
    Edge(int v, int wt) {
        V = v;
        this->wt = wt;
    }
};

void bellmanFord(vector<vector<Edge>> graph, int v, int src) { // O(V * E)
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    for(int i = 0; i < v-1; i++) { // V-1 => V
        for(int u = 0; u < v; u++) { // E
            for(Edge e : graph[u]) {
                if(dist[e.V] > dist[u] + e.wt) {
                    dist[e.V] = dist[u] + e.wt;
                }
            }
        }
    }

    for(int i=0; i <v;i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}

int main() {
    int v = 5;
    vector<vector<Edge>> graph(v);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,-4));

    graph[2].push_back(Edge(3,2));

    graph[3].push_back(Edge(4,4));

    graph[4].push_back(Edge(1,-1));

    bellmanFord(graph, v, 0);
}