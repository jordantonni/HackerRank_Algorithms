// https://www.hackerrank.com/challenges/primsmstsub/problem
// Jordan Tonni
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct edge
{
    int node;
    int weight;
};
class edgeGreater
{
    public:
    bool operator()(const edge& lhs, const edge& rhs) const
    {
        return lhs.weight > rhs.weight;
    }
};
vector<vector<edge> > adjList;
vector<bool> visited;
vector<edge> mst;

int init()
{
    int nodes, edges;
    cin >> nodes >> edges;
    adjList.resize(nodes + 1, vector<edge>());
    visited.resize(nodes + 1, false);
    
    while(edges--){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(edge{v,w});
        adjList[v].push_back(edge{u,w});
    }
    
    int start;
    cin >> start;
    return start;
}

void primsMST(const int start)
{
    priority_queue<edge, vector<edge>, edgeGreater> q;
    q.push(edge{start,0});
    
    while(!q.empty()){
        edge current = q.top();
        q.pop();
        
        if(visited[current.node])
            continue;
        
        visited[current.node] = true;
        mst.push_back(current);
        
        for(int i = 0; i < adjList[current.node].size(); ++i){
            if(!visited[adjList[current.node][i].node]){
                q.push(adjList[current.node][i]);
            }
        }
    }
}


int main() 
{
    int s { init() };
    primsMST(s);
    
    int mstWeight { 0 };
    for(const auto e : mst){
        mstWeight += e.weight;
    }
    cout << mstWeight << endl;
    
    return 0;
}



