// https://www.hackerrank.com/challenges/insertionsort1
// Jordan Tonni


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int len;
    vector<int> A;
    cin >> len;
    
    while(len--){
        int val;
        cin >> val;
        A.push_back(val);
    }
    
    int i = A.size() - 2;
    int e = A[A.size()-1];
    
    while(i >= 0 && A[i] > e ){
        A[i+1] = A[i];
        --i;
        
        for(auto x : A)
            cout << x << " ";
        cout << endl;
    }
    
    A[i+1] = e;
    
    for(auto x : A)
        cout << x << " ";
    
    
    return 0;
}

