// https://www.hackerrank.com/challenges/even-tree/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using std::vector;
using std::pair;
using edge = pair<int,int>;

class Graph_Adj_List
{
public:
    vector<vector<edge> > adjList;
    mutable vector<bool> visited;

    explicit Graph_Adj_List(const int size);

    void makeEdge(const int u, const int v, const int w);
};

class edgeGreater
{
public:
    bool operator()(const edge& lhs, const edge& rhs) const
    {
        return lhs.second > rhs.second;
    }
};

Graph_Adj_List::Graph_Adj_List(const int size)
    : adjList{ size + 1, vector<edge>() }
{
    visited = vector<bool>(size + 1, false);
}

void Graph_Adj_List::makeEdge(const int u, const int v, const int w)
{
    adjList[u].push_back({ v,w });
    adjList[v].push_back({ u,w });
}

vector<int> nodeRank;

Graph_Adj_List makeGraph()
{
    int n,k;
    cin >> n >> k;
    Graph_Adj_List graph { n };
    nodeRank.resize(n + 1, 1);

    while(k--){
        int u,v;
        cin >> u >> v;
        graph.makeEdge(u, v, 1);
    }
    return graph;
}

int dfs(Graph_Adj_List& graph, int s)
{
    if(graph.visited[s])
        return 0;
    graph.visited[s] = true;

    for(int i = 0; i < graph.adjList[s].size(); ++i){
        nodeRank[s] += dfs(graph, graph.adjList[s][i].first);
    }
    return nodeRank[s];
}

int main()
{
    Graph_Adj_List g = makeGraph();
    
    dfs(g, 1);
    size_t forestCount { 0 };
    for(int i = 2; i < nodeRank.size(); ++i){
        if(!(nodeRank[i] % 2))
            ++forestCount;
    }

    cout << forestCount << endl;
    return 0;
}



