// https://www.hackerrank.com/challenges/anagram/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int N;
    cin >> N;
    
    while(N--){
        
        string s;
        cin >> s;
        int string_length = s.length();

        if(string_length % 2 != 0){
            cout << -1 << endl;
            continue;
        }

        int mid = string_length / 2;
        string s1 = s.substr(0, mid);
        string s2 = s.substr(mid);

        vector<int> A(26,0);

        for(int i = 0; i < s1.length() ; ++i){
            int indx = (s1.at(i) - 'a');
            ++(A[indx]);
        }

        for(int i = 0 ; i < s2.length() ; ++i){
            int indx = (s2.at(i) - 'a');
            if(A[indx] > 0)
                --A[indx];
        }

        int result {0};
        for(auto e : A)
            result += e;
        cout << result << endl;
    }
    
    
    return 0;
}


