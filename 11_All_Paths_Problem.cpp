#include<iostream>
#include<vector>
#include<string>
#include<list>
using namespace std;

class Graph {
    int v;
    list<int> *l;
public:
    Graph(int v) {
        this-> v = v;
        l = new list<int> [v];
    }
    void addEdge(int u, int v) { // Directed Graph
        l[u].push_back(v);
    }

    void pathHelper(int src, int dest, vector<bool> &vis, string &path) { // O(n = e)
        if(dest == src) {
            cout << path << dest << endl;
            return ;
        }
        vis[src] = true;
        path += to_string(src);
        
        list<int> neighbours = l[src];

        for(int v : neighbours) {
            if(!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }
        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }
    void printAllPath(int src, int dest) {
        vector<bool> vis(v, false);
        string path = "";
        pathHelper(src, dest, vis, path);
    }
};

int main() {
    int v = 6;
    Graph graph(v);

    graph.addEdge(5, 2);
    graph.addEdge(2, 3);
    graph.addEdge(5, 0);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(3, 1);
    graph.addEdge(0, 3);

    graph.printAllPath(5, 1);
}