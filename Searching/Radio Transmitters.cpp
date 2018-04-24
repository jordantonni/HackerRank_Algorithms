// https://www.hackerrank.com/challenges/hackerland-radio-transmitters/problem
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
    unordered_set<int> exists;
    vector<int> v;
    int n, k;
    cin >> n >> k;
    
    while(n--){
        int val;
        cin >> val;
        
        auto search = exists.find(val);
        if(search == exists.end()){
            v.push_back(val);
            exists.insert(val);
        }
    }
    
    sort(begin(v), end(v));
    
    int target, lowB, middleHouse, count = 0, leftMostHouse = 0;
    n = v.size();
    
    while(leftMostHouse < n){
        target = v[leftMostHouse] + k; // Ideally, the further right house in range from current house
        lowB = lower_bound(begin(v), end(v), target) - begin(v); // Index to house either == to or greater than max range
        if(lowB >= n || v[lowB] > target)
            --lowB; // Closest house at max range was too far, make lowB one less which, due to sorted houses, is def in range
        
        middleHouse = v[lowB]; // Record position of middleHouse in range;
        
        // Now we need to find the furtherst in range from middle;
        
        target = middleHouse + k;
        lowB = lower_bound(begin(v), end(v), target) - begin(v); // Get index to house either at max distance or just too far
        if(lowB >= n || v[lowB] > target) 
            --lowB; // House is just too far, go back to prev index which is def in range
        
        leftMostHouse = lowB + 1;
        ++count;
    }
    
    cout << count << endl;
    
    return 0;
}

