// https://www.hackerrank.com/challenges/mark-and-toys/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n, k;
    cin >> n >> k;
    vector<long long> prices(n);
    for(int i=0; i<n; ++i)
        cin >> prices[i];
    
    sort(begin(prices), end(prices));
    
    long long  total{0};
    size_t numToys{0};
    for(const auto toy : prices){
        if(total+toy <= k){
            ++numToys;
            total += toy;
        }
    }
        
    cout << numToys;
    return 0;
}

