// https://www.hackerrank.com/challenges/minimum-loss/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <set>
#include <limits>
using namespace std;

using ll = long long;

int main()
{
    set<ll> prices;
    int n;
    cin >> n;
    ll val;
    cin >> val;
    prices.insert(val);
    --n;
    
    ll minV = numeric_limits<ll>::max();
    
    while(n--){
        ll val;
        cin >> val;
        
        auto up = prices.upper_bound(val);
        if(up != end(prices)){
            minV = std::min(minV, *up - val);
        }
        prices.insert(val);
    }
    
    cout << minV << endl;
    return 0;
}

