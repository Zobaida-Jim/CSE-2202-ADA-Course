#include<iostream>
#include<vector>
using namespace std;

class Edge {
public:
    int u, v, wt;
    Edge(int u, int v, int wt) {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }
};

class Graph {
public:
    vector<Edge> edges;
    int V;
    vector<int> par;
    vector<int> rank;

    Graph(int v) {
        V = v;

        for(int i = 0; i < V; i++) { // union find ds
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if(par[x] == x) {
            return x;
        }

        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v) {
        int parU = find(u);
        int parV = find(v);

        if(rank[parU] == rank[parV]) {
            par[parV] = parU;
            rank[parU]++;
        }
        else if(rank[parU] > rank[parV]) {
            par[parV] = parU;
        }
        else {
            par[parU] = parV;
        }
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(Edge(u, v, wt));
    }

    void kruskal() { //TC = O(ElogE)
        int minCost = 0;
        int count = 0;
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b){return a.wt < b.wt;}); // Lembda function
        // (ElogE)
        for(int i = 0; i < edges.size() && count < V-1; i++) {
            Edge e = edges[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU != parV) { // No cycle edge
                unionByRank(parU, parV);
                minCost += e.wt;
                count++;
            }
        }
        cout << minCost << endl;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.kruskal();
}