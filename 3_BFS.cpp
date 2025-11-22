#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

class Graph {
    int V;
    list<int> *l;
public:
    Graph(int V) {
        this-> V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void BFS(int src) { // BFS
        queue<int> q;
        q.push(src);
        vector<bool> visit(V, false); // Initialize this with 0
        visit[src] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            list<int> neighbours = l[u];
            for(auto v : neighbours) {
                if(!visit[v]) {
                    visit[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl; 
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

    graph.BFS(0);
}