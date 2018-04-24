// https://www.hackerrank.com/challenges/missing-numbers/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n;
    cin >> n;
    vector<int>A;
    A.reserve(n);
    while(n--){
        int val;
        cin >> val;
        A.push_back(val);
    }
    int m;
    cin >> m;
    vector<int>B;
    B.reserve(m);
    while(m--){
        int val;
        cin >> val;
        B.push_back(val);
    }
    
    vector<int> freqA(100000, 0);
    vector<int> freqB(100000, 0);
    
    for(int i = 0; i < A.size(); ++i){
        ++(freqA[A[i]]);
    }
    for(int i = 0; i < B.size(); ++i){
        ++(freqB[B[i]]);
    }
    
    for(int i = 0; i < freqA.size(); ++i){
        if(freqA[i] != freqB[i])
            cout << i << " ";
    }
    
    
    return 0;
}

