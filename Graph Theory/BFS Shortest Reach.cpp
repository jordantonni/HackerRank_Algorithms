// https://www.hackerrank.com/challenges/bfsshortreach/problem
// Jordan Tonni
//
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Graph
{
    vector<vector<int> > adjList;
    vector<bool> visited;
    vector<int> dist;
    int weight;
    int start;
    
    explicit Graph(const int n)
        : adjList(n+1, vector<int>()), visited(n+1, false), dist(n+1, -1), weight { 6 }, start { -1 }
        {}
    
    void makeEdge(const int u, const int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
};

Graph makeGraph()
{
    int n, k;
    cin >> n >> k;
    Graph g(n);
    
    while(k--){
        int u, v;
        cin >> u >> v;
        g.makeEdge(u,v);
    }
    
    int s;
    cin >> s;
    g.start = s;
    
    return g;
}

void BFS(Graph& g)
{
    queue<int> q;
    q.push(g.start);
    g.dist[q.front()] = 0;
    g.visited[q.front()] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        for(const auto e : g.adjList[node]){
            if(!g.visited[e]){
                q.push(e);
                g.dist[e] = g.dist[node] + 1;
                g.visited[e] = true;
            }
        }
    }
}


int main() 
{
    int Q;
    cin >> Q;
    
    while(Q--){
        Graph g = makeGraph();
        BFS(g);
        
        // cout each dist element from g * g.weight
        for(int i = 1; i < g.dist.size(); ++i){
            if(i != g.start){
                if(g.visited[i])
                    cout << g.dist[i] * g.weight << " ";
                else
                    cout << "-1 ";
            }
        }
        cout << endl;
    }
        
    return 0;
}


