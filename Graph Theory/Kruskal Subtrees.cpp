// https://www.hackerrank.com/challenges/kruskalmstrsub/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct UnionFind
{
    vector<int> parents;
    vector<int> rank;

    explicit UnionFind(const int n)
        : parents(n + 1, -1)
        , rank(n + 1, 1)
    {
        for(int i = 0; i < n + 1; ++i){
            parents[i] = i;
        }
    }

    int root(int u)
    {
        while(parents[u] != u){
            parents[u] = parents[parents[u]];
            u = parents[u];
        }
        return parents[u];
    }

    bool connected(const int u, const int v)
    {
        return root(u) == root(v);
    }

    void connect(int u, int v)
    {
        if(connected(u, v))
            return;

        int rootU { root(u) };
        int rootV { root(v) };

        if(rank[rootU] > rank[rootV]){
            parents[rootV] = rootU;
            rank[rootU] += rank[rootV];
        }
        else{
            parents[rootU] = rootV;
            rank[rootV] += rank[rootU];
        }
    }
};

struct Edge
{
    int u;
    int v;
    int w;

    bool operator<(const Edge& rhs) const
    {
        /*if(this->w == rhs.w){
            return (this->w + this->u + this->v) > (rhs.w + rhs.u + rhs.v);
        }
        else
        */
            return this->w > rhs.w;
    }
};

struct Graph
{
    vector<vector<pair<int,int> > > adjList;

    explicit Graph(const int n)
        : adjList(n + 1, vector<pair<int,int> >())
    {}

    void makeEdge(const int u, const int v, const int w)
    {
        adjList[u].push_back({ v,w });
        adjList[v].push_back({ u,w });
    }
};

Graph makeGraph()
{
    int n,k;
    cin >> n >> k;

    Graph g { n };

    while(k--){
        int u;
        int v;
        int w;
        cin >> u >> v >> w;
        g.makeEdge(u, v, w);
    }

    return g;
}

int Kruskal(Graph& g)
{
    priority_queue<Edge> q;
    UnionFind connectedComps { static_cast<int>(g.adjList.size()) };
    int mstWeight { 0 };

    for(int i = 0; i < g.adjList.size(); ++i){
        for(const auto& e : g.adjList[i]){
            Edge edg { i, e.first, e.second };
            q.push(edg);
        }
    }

    int numEdges = q.size();
    for(int i = 0; i < numEdges; ++i){
        Edge e = q.top();
        q.pop();

        if(!connectedComps.connected(e.u, e.v)){
            mstWeight += e.w;
            connectedComps.connect(e.u, e.v);
        }
    }
    return mstWeight;
}

int main()
{
    Graph g = makeGraph();
    cout << Kruskal(g) << endl;
    
    return 0;
}


