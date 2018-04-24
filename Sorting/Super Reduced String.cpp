// https://www.hackerrank.com/challenges/reduced-string/problem
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <deque>
using namespace std;


int main() 
{
    string s;
    cin >> s;
    stack<char> st;
    
    if(s.length() == 0)
    {
        cout << "Empty String" << endl;
    }
    
    st.push(s.at(0));
    
    for (int i=1 ; i<s.length() ; ++i)
    {
        if(!st.empty() && s[i] == st.top())
        {
            st.pop();
        }
        else
        {
            st.push(s.at(i));
        }
    }
    
    deque<char> d;
    
    if(st.empty())
    {
        cout << "Empty String";
        return 0;
    }
    
    while(!st.empty()){
        d.push_front(st.top());
        st.pop();
    }
    
    for(auto e : d)
        cout << e;
    cout << endl;
    
    return 0;
}

