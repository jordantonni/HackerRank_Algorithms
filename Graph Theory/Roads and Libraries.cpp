// https://www.hackerrank.com/challenges/torque-and-development/problem
// Jordan Tonni
//
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<long long> > adjList;
vector<bool> visited;
long long cities,roadCost,libCost;
long long roads;
long long allLibsCost;
long long pathLength = 0;

void init()
{
    cin >> cities >> roads >> libCost >> roadCost;
    adjList = vector<vector<long long> >(cities + 1, vector<long long>());
    visited = vector<bool>(cities + 1, false);
    allLibsCost = cities * libCost;

    while(roads--){
        int u,v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

void dfs(int s)
{
    visited[s] = true;

    for(const auto u : adjList[s]){
        if(!visited[u]){
            ++pathLength;
            dfs(u);
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--){
        pathLength = 0;
        allLibsCost = 0;

        init();
        int connectedComp = 0;
        for(int i = 1; i < cities + 1; ++i){
            if(!visited[i]){
                dfs(i);
                ++connectedComp;
            }
        }

        long long totalCost = pathLength * roadCost;
        totalCost += libCost * connectedComp;

        cout << min(totalCost, allLibsCost) << endl;

    }
    
    return 0;
}




