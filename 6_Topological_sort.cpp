/// Using BFS (Kahn's Algorithm)

#include<iostream>
#include<vector>
#include<list>
#include<queue>
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
        l[u].push_back(v); /// U--->V Directed Graph
    }

    void calIndegree(vector<int> &indeg) {
        for(int u = 0; u < V; u++) {
            list<int> neighbour = l[u];
            for(auto v : neighbour) {
                indeg[v]++;
            }
        }
    }

    void topoSort() { /// Kahn's Algo
        vector<int> indeg(V, 0);
        calIndegree(indeg);
        queue<int> q;

        // Starting with Indegree = 0
        for(int u = 0; u < V; u++) {
            if(indeg[u] == 0) {
                q.push(u);
            }
        }

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            list<int> neighbour = l[curr];
            for(auto v : neighbour) {
                indeg[v]--;
                if(indeg[v] == 0) { // No pending Dependency
                    q.push(v);
                }
            }
        }

        cout << endl;
    }
};

int main() {

    Graph graph(6);

    graph.addEdge(5,0);
    graph.addEdge(4,0);
    graph.addEdge(5,2);
    graph.addEdge(2,3);
    graph.addEdge(3,1);
    graph.addEdge(4,1);

    graph.topoSort();
}