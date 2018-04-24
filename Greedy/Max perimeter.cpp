// https://www.hackerrank.com/challenges/maximum-perimeter-triangle/problem
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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    
    sort(begin(v), end(v), greater<int>());
    
    int i = 0;
    bool found = false;
    for( ; i < v.size() - 2; ++i){
        if(v[i] < (v[i+1]+v[i+2])){
            found = true;
            break;
        }
    }
    
    
    if(found)
        cout << v[i+2] << " " << v[i+1] << " " << v[i] << endl;
    else
        cout << "-1" << endl;
    
    
    return 0;
}


