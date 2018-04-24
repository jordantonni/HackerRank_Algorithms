// https://www.hackerrank.com/challenges/greedy-florist/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> prices(n);
    for(int i=0; i<n; ++i)
        cin >> prices[i];
        
    sort(begin(prices), end(prices), std::greater<int>());
    
    size_t total {0};
    for(int i=0; i<prices.size(); ++i){
        int numFlo = std::floor(i / k) + 1;
        total += numFlo * prices[i];
    }
    
    cout << total;
    
    return 0;
}

