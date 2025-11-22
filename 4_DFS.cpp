#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void DFS(int u, vector<bool> &visit) { // TC = O(V + E)
        visit[u] = true;
        cout << u << " ";
        list<int> neighbour = l[u];

        for(auto v : neighbour) {
            if(!visit[v]) {
                visit[v] = true;
                DFS(v, visit);
            }
        }
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,3);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,5);
    graph.addEdge(4,5);
    graph.addEdge(5,6);

    vector<bool> visit(7, false);
    graph.DFS(0, visit);
    cout << endl;
}