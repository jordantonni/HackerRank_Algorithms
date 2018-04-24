// https://www.hackerrank.com/challenges/stone-division-2/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

vector<long long> S;
map<long long,long long> dp;

long long rec(const long long pileSize)
{
    if(dp.find(pileSize) != end(dp))
        return dp.find(pileSize)->second;

    long long ans { 0 };
    for(const long long y : S){
        if(pileSize % y == 0 && pileSize / y > 1)
            ans = max(ans, 1 + ((pileSize / y) * rec(y)));
    }

    dp[pileSize] = ans;
    return ans;
}

int main()
{
    int tests;
    cin >> tests;

    while(tests--){
        long long n;
        int vals;
        cin >> n >> vals;
        S.resize(vals);
        for(int i = 0; i < vals; ++i){
            cin >> S[i];
        }

        cout << rec(n) << endl;
        S.clear();
        dp.clear();

    }
    
    return 0;
}
