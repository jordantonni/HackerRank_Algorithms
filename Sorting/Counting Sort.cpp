// https://www.hackerrank.com/challenges/countingsort1
// Jordan Tonni


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void readin(vector<int>& v)
{
    int n;
    cin >> n;
    while(n--){
        int val;
        cin >> val;
        v.push_back(val);
    }
}


int main() 
{
    vector<int> freq (100, 0);
    vector<int> input;
    readin(input);
    
    for(int i=0; i < input.size(); ++i){
        int val = input[i];
        ++(freq[val]);
    }
    
    for(const auto& e : freq)
        cout << e << " ";
    cout << endl;
    
    return 0;
}

