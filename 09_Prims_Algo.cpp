#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> *l; // int , int : neighbour, wt
public:
    Graph(int v) {
        V = v;
        l = new list<pair<int, int>> [V];
    }

    void addEdge(int u, int v, int wt) { // Undirected + weighted
        l[u].push_back(make_pair(v, wt));
        l[v].push_back(make_pair(u, wt));
    }

    void primsAlgo(int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // (wt, v) --> mean heap
        vector<bool> mst(V, false);

        pq.push(make_pair(0, src));
        int ans = 0;

        while(pq.size() > 0) {
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();

            if(!mst[u]) {
                mst[u] = true;
                ans += wt;
                list<pair<int, int>> neighbour = l[u];

                for(pair<int, int> n : neighbour) {
                    int v = n.first;
                    int curr_cost = n.second;
                    pq.push(make_pair(curr_cost, v));
                }
            }
        }

        cout << ans << endl;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 10); // u, v, wt
    graph.addEdge(0, 3, 30);
    graph.addEdge(0, 2, 15);

    graph.addEdge(1, 3, 40);

    graph.addEdge(2, 3, 50);

    graph.primsAlgo(0);
    
}