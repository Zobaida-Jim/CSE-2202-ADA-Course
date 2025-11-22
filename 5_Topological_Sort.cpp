/// Using DFS

#include<iostream>
#include<list>
#include<vector>
#include<stack>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int v) {
        V = v;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) { // TC = O(V + E), SC = (N)
        l[u].push_back(v); //Only U--->V because it is Directed Graph
    }

    void topoHelper(int u, vector<bool> &vis, stack<int> &s) { // Real DFS
        vis[u] = true;

        list<int> neighbour = l[u];
        for(auto v : neighbour) {
            if(!vis[v]) {
                topoHelper(v, vis, s);
            }
        }
        s.push(u);
    }

    void topotSort() {
        vector<bool> vis (V, false);
        stack<int> s;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                topoHelper(i, vis, s);
            }
        }

        // Print Topoogical Sort
        while(s.size() > 0) {
            cout << s.top() << " ";
            s.pop();
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

    graph.topotSort();
}