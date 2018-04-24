// https://www.hackerrank.com/challenges/maximizing-xor/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int L, R;
    cin >> L >> R;
    
    int max = 0;
     for(int i=L; i<=R; ++i){
         for(int j=i; j<=R; ++j){
             int temp = i ^ j;
             if(temp > max)
                 max = temp;
         }
     }
    cout << max << endl;
    return 0;
}

