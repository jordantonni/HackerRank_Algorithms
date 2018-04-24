// https://www.hackerrank.com/challenges/flipping-bits/problem
// Jordan Tonni
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;


int main() {
    size_t n;
    unsigned int digit;
    cin >> n;
    
    while(n--){
        cin >> digit;
        unsigned int mask = std::numeric_limits<unsigned int>::max();
        unsigned output = digit ^ mask;
        cout << output << endl;
    }
    
    return 0;
}


