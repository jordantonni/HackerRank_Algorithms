// https://www.hackerrank.com/challenges/sum-vs-xor/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t zeros = 0;
    size_t count = 0;
    long n = 0;
    cin >> n;
    
    while(n){
        (n & 1) ? : ++zeros;
        n >>= 1;
    }
    
    count = pow(2, zeros);
    cout << (1L << zeros) << endl;
    
    return 0;
}

