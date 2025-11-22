#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<utility>
using namespace std;
// Using Edge list

class Edge {
public:
    int V;
    int wt;

    Edge(int v, int w) {
        V = v;
        wt = w;
    }
};

void dijkstra(int src, vector<vector<Edge>> graph, int v) { // TC = O((V + E)logV)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Mean heap
    vector<int> dis(v, INT_MAX);
    pq.push(make_pair(0, src));
    dis[src] = 0;

    while(pq.size() > 0) {
        int u = pq.top().second;
        pq.pop();
        vector<Edge> edges = graph[u];
        for(Edge e : edges) { 
            if(dis[e.V] > dis[u] + e.wt) {
                dis[e.V] = dis[u] + e.wt;
                pq.push(make_pair(dis[e.V],e.V));
            }
        }
    }

    for(int d : dis) {
        cout << d << " ";
    }
    cout << endl;
}

int main() {
    int V = 6;
    vector<vector<Edge>> graph(V); // Vector of Edge List

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(3,7));
    graph[1].push_back(Edge(2,1));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstra(0, graph, V);
}