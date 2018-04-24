// https://www.hackerrank.com/challenges/quicksort1
// Jordan Tonni


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int size;
    cin >> size;
    vector<int> input, left, right;
    int equal;
    
    while(size--){
        int temp;
        cin >> temp;
        input.push_back(temp);
    }
    
    equal = input[0];
    
    for(int i = 1; i < input.size(); ++i){
        if(input[i] < equal)
            left.push_back(input[i]);
        else
            right.push_back(input[i]);
    }
    
    for(const auto e : left)
        cout << e << " ";
    cout << equal << " ";
    for(const auto e : right)
        cout << e << " ";
    cout << endl;
    
    
    return 0;
}

