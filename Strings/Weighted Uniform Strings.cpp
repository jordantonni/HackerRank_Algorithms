// https://www.hackerrank.com/challenges/weighted-uniform-string/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <memory>
using namespace std;

int getWeight(const char s)
{
    return (s - 'a') + 1;
}

unordered_set<int> getUniformSubstrings(const string& s)
{
    int len = s.length();
    unordered_set<int> weights;
    
    for(int i = 0; i < len; ++i)
    {
        int w = getWeight(s.at(i));
        weights.insert(w);
        int count = 1;
        
        while(i < len-1  && s.at(i+1) == s.at(i))
        {
            ++i;
            ++count;
            weights.insert(count * w);
        }
    }
    return weights;
}


int main() {
    
    string s;
    int N;
    cin >> s >> N;
    
    unordered_set<int> weights = getUniformSubstrings(s);
    
    while(N--)
    {
        int val;
        cin >> val;
        
        auto search = weights.find(val);
        if(search != end(weights))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}

