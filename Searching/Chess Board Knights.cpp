// https://www.hackerrank.com/challenges/knightl-on-chessboard/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

inline bool isValidCell(const int x, const int y, const int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

int minMoves(int x, int y, int n)
{
    vector<vector<int> > distance(n, vector<int>(n, -1));
    vector<pair<int,int> > moves {
            make_pair(x, y),
            make_pair(y, x),

            make_pair(-x, -y),
            make_pair(-y, -x),

            make_pair(-y, x),
            make_pair(x, -y),

            make_pair(-x, y),
            make_pair(y, -x),
        };

    queue<pair<int,int> > Q;
    Q.push(make_pair(0, 0));
    distance[0][0] = 0;

    while(!Q.empty()){
        pair<int,int> position = Q.front();
        Q.pop();

        for(const auto& move : moves){
            int newX = position.first + move.first;
            int newY = position.second + move.second;
            if(isValidCell(newX, newY, n) && distance[newX][newY] == -1){
                distance[newX][newY] = distance[position.first][position.second] + 1;

                if(newX == n - 1 && newY == n - 1)
                    return distance[newX][newY];

                Q.push(make_pair(newX, newY));
            }
        }
    }

    return distance[n - 1][n - 1];
}

int main()
{
    int n;
    cin >> n;

    for(int i = 1; i < n; ++i){
        for(int j = 1; j < n; ++j){
            cout << minMoves(i, j, n) << " ";
        }
        cout << endl;
    }
    
    return 0;
}



