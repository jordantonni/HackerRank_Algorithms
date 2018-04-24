// https://www.hackerrank.com/challenges/lonely-integer/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    
    int element;
    cin >> element;
    --n;
    
    while(n--){
        int in;
        cin >> in;
        element ^= in;
    }
    
    cout << element;
    return 0;
}


