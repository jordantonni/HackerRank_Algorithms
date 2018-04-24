// https://www.hackerrank.com/challenges/insertionsort2
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
    
    if(A.size() <= 1){
        for(auto e : A)
            cout << e;
        return 0;
    }
    
    // Start from the 2nd element, go to the end
    for(int i = 1; i < A.size(); ++i){
        
        //Store the current element and counter at same position as i
        int e = A[i];
        int j = i;
        
        //While there are elements to the left and they are > the saved current element
        //Shift the element at j-1 to position j and keep going left until it doesnt hold
        // Either we are at the start of the array(position 0) or we found a smaller element
        while(j > 0 && A[j-1] > e){
            A[j] = A[j-1];
            --j;
        }
        // Put the saved value into its correct position
        A[j] = e;
        
        for(auto e : A)
            cout << e << " ";
        cout << endl;
    }
    
    
        
    return 0;
}

