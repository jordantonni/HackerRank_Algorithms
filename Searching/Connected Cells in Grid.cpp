// https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
// Jordan Tonni
//
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <limits>
#include <queue>
using namespace std;

int n,m;

inline vector<pair<int,int> > getConnectedCells(int x, int y)
{
    vector<pair<int,int> > all
        {
            make_pair(x - 1, y - 1),
            make_pair(x - 1, y),
            make_pair(x - 1, y + 1),
            make_pair(x, y - 1),
            make_pair(x, y + 1),
            make_pair(x + 1, y - 1),
            make_pair(x + 1, y),
            make_pair(x + 1, y + 1)
        };
    vector<pair<int,int> > valid;

    for(const auto& cell : all){
        if(cell.first >= 0 && cell.first < n && cell.second >= 0 && cell.second < m)
            valid.push_back(cell);
    }

    return valid;
}

int maxR { numeric_limits<int>::min() };

void DFS(int i, int j, vector<vector<int> >& matrix)
{
    queue<pair<int,int> > st;
    int countr = 0;

    st.push(make_pair(i, j));

    while(!st.empty()){

        if(matrix[st.front().first][st.front().second] == 1){
            ++countr;
        }
        matrix[st.front().first][st.front().second] = -1; // Seen

        vector<pair<int,int> > connected = getConnectedCells(st.front().first, st.front().second);
        st.pop();

        for(const auto& cell : connected){
            if(matrix[cell.first][cell.second] > 0){
                st.push(cell);
            }
        }
    }

    maxR = std::max(maxR, countr);
}

int main()
{
    cin >> n >> m;
    vector<vector<int> > matrix(n, vector<int>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> matrix[i][j];
        }
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(matrix[i][j] > 0)
                DFS(i, j, matrix);
        }
    }

    cout << maxR << endl;
    return 0;
}



