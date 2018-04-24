// https://www.hackerrank.com/challenges/runningtime
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int len;
    cin >> len;
    vector<int> A;
    while(len--){
        int val;
        cin >> val;
        A.push_back(val);
    }
    
    int count = 0;
    
    for(int i = 1; i < A.size(); ++i){
        
        int x = A[i];
        int j = i;
        
        while(j > 0 && A[j-1] > x){
            A[j] = A[j-1];
            --j;
            ++count;
        }
        A[j] = x;
    }
    
    cout << count << endl;
    
    return 0;
}

