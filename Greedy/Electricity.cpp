// https://www.hackerrank.com/challenges/pylons/problem
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
    int last = -1;
    int towers = 0;
    cin >> n >> k;
    vector<int> cities(n);
    vector<int> prev(n);
    
    // Prev[i] holds the index of the closest tower to the left of city i
    for(int i=0; i<n; ++i){
        cin >> cities[i];
        if(cities[i])
            last = i;
        prev[i] = last;
    }
    
    // i holds the current city we are jumping from
    for(int i=0; i<n; ){
        int tower = prev[ min(i+k-1, n-1) ]; // Get furthest to the right tower in range, or last element in array 
        
        // If the prev tower from our max jump to the right is the one we came from, we can't go further right, end it
        if(tower == -1 || tower + k <= i){
            cout << "-1";
            return 0;
        }
        ++towers;
        i = tower + k; // Set our new current city to be 1 just right of the range of our current tower
    }
    
    cout << towers;
        
    return 0;
}

