// https://www.hackerrank.com/challenges/coin-change/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, long long> cache;
inline string makeKey(const int amount, const int idx)
{
    string s = to_string(amount) + "-" + to_string(idx);
    return s;
}
long long getCombos(const vector<int>& coins, const int amount, const int idx)
{
    if(cache.count(makeKey(amount,idx)))
        return cache.at(makeKey(amount,idx));
    if(amount == 0)
        return 1;
    if(amount < 0)
        return 0;
    
    long long numWays = 0;
    for(int i = idx; i < coins.size(); ++i){
        numWays += getCombos(coins, amount - coins[i], i);
    }
    
    cache[makeKey(amount,idx)] = numWays;
    return numWays;
    
}


long long getCombos(const vector<int>& coins, const int amount)
{
    return getCombos(coins, amount, 0);
}
    

int main() {
    
    int amount, numCoins;
    cin >> amount >> numCoins;
    vector<int> coins(numCoins, 0);
    for(int i=0; i<numCoins; ++i){
        cin >> coins[i];
    }
    
    cout << getCombos(coins, amount) << endl;
    return 0;
}


