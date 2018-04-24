// https://www.hackerrank.com/challenges/cut-the-tree/problem
// Jordan Tonni
//


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> node_val;
vector<vector<int> > adj;
vector<int> subtree_sum;
vector<bool> visited;
int total;

void init()
{
    int n;
    cin >> n;
    adj.resize(n);

    for(int i = 0; i < n; ++i){
        int val;
        cin >> val;
        node_val.push_back(val);
        total += val;
        visited.push_back(false);
        subtree_sum.push_back(0);
    }

    for(int i = 0; i < n - 1; ++i){
        int u,v;
        cin >> u >> v;
        --u , --v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int dfs(int i)
{
    visited[i] = true;

    for(int next : adj[i]){
        if(!visited[next]){
            subtree_sum[i] += dfs(next);
        }
    }
    subtree_sum[i] += node_val[i];
    return subtree_sum[i];
}

int main()
{
    init();
    dfs(2);

    int min { numeric_limits<int>::max() };
    for(const auto e : subtree_sum){
        min = std::min(abs(e - (total - e)), min);
    }

    cout << min << endl;
    
    return 0;

}

