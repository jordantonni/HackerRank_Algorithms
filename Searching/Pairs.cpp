// https://www.hackerrank.com/challenges/pairs/problem
// Jordan Tonni


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_set>
using namespace std;


int main() 
{
    int n, k;
    cin >> n >> k;
    unordered_set<int> hashT;
    while(n--){
        int val;
        cin >> val;
        hashT.insert(val);
    }
    
    size_t count {0};
    
    for(auto it = begin(hashT); it != end(hashT); ++it){
        if(hashT.find(*it + k) != end(hashT))
            ++count;
    }
    
    cout << count << endl;
    return 0;
}

