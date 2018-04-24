// https://www.hackerrank.com/challenges/pangrams/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    
    vector<int> freq(26,0);
    
    for(int i = 0; i < s.length(); ++i){
        char ch = tolower(s[i]);
        if(ch >= 'a' && ch <= 'z')
            ++freq[ch - 'a'];
    }
    
    for(const auto& c : freq)
        if(c == 0){
            cout << "not pangram" << endl;
            return 0;
        }
    
    cout << "pangram";
    
    return 0;
}


