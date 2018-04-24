// https://www.hackerrank.com/challenges/angry-children/problem
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
    vector<int> v(n);
    for(int i=0; i<n; ++i)
        cin >> v[i];
    
    std::sort(begin(v), end(v), std::greater<int>());
    int delta = v[0] - v[v.size()-1];
    for(int i=0; i<n-k+1; ++i){
        if(v[i] - v[i+(k-1)] < delta)
            delta = v[i] - v[i+(k-1)];
    }
    
    cout << delta;
    return 0;
}

