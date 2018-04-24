// https://www.hackerrank.com/challenges/the-quickest-way-up/problem
// Jordan Tonni

#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<vector<int> > list;
vector<int> visited;
vector<int> path;

void init()
{
    list.resize(101, vector<int>());
    visited.resize(101, false);
    path.resize(101, -1);
}

void cleanUp()
{
    for(auto e : list)
        e.clear();
    list.clear();
    visited.clear();
    path.clear();
}

void makeGraph()
{
    list[100].clear();

    int ladders;
    cin >> ladders;
    while(ladders--){
        int start,end;
        cin >> start >> end;
        list[start].push_back(end);
    }

    int snakes;
    cin >> snakes;
    while(snakes--){
        int start,end;
        cin >> start >> end;
        list[start].push_back(end);
    }

    for(int i = 1; i < 101; ++i){
        for(int j = 1; j < 7; ++j){
            if(i + j < 101){
                if(list[i + j].empty()){
                    list[i].push_back(i + j);
                }
                else{
                    list[i].push_back(list[i + j][0]);
                }
            }
        }
    }
}

void bfs()
{
    queue<int> q;
    q.push(1);
    path[1] = 0;
    visited[q.front()] = true;

    while(!q.empty()){
        int current = q.front();
        q.pop();

        for(int i = 0; i < list[current].size(); ++i){
            int adj = list[current][i];
            if(!visited[adj]){
                q.push(list[current][i]);
                visited[adj] = true;
                path[adj] = path[current] + 1;
            }
        }
    }
}

int main()
{
    int trials;
    cin >> trials;

    while(trials--){
        init();
        makeGraph();
        bfs();
        
        cout << path[100] << endl;
        cleanUp();

    }
    return 0;
}


