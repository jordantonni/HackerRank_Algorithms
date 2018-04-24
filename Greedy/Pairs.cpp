// https://www.hackerrank.com/challenges/beautiful-pairs/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() 
{
    int n;
    cin >> n;
    int total { n };
    unordered_multiset<int> hashSet;
    vector<int> v(n,0);
    
    while(n--){
        int val;
        cin >> val;
        hashSet.insert(val);
    }
    for(int i = 0; i < total; ++i)
        cin >> v[i];
    
    size_t pairs { 0 };
    for(const auto num : v){
        auto it = hashSet.equal_range(num);
        if(it.first != it.second){
            ++pairs;
            hashSet.erase(it.first);
        }
    }
    
    if(pairs == total)
        cout << total-1 << endl;
    else
        cout << pairs+1 << endl;
    
    return 0;
}

