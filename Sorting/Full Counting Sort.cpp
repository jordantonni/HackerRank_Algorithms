// https://www.hackerrank.com/challenges/countingsort4
// Jordan Tonni


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

using data = pair<int,string>;

int readin(vector<data>& A, int& n)
{
    cin >> n;
    int ret = n;
    while(n--){
        int v;
        string s;
        cin >> v >> s;
        A.push_back(make_pair(v,s));
    }
    
    return ret;
}

vector<vector<int> > countingSort(vector<data>& A)
{
    vector<vector<int> > v(100, vector<int>());
    for(int i = 0; i < A.size(); ++i){
        v[A[i].first].push_back(i);
    }
    return v;
}

int main() 
{
    int n;
    vector<data> A;
    int total = readin(A, n);
    vector<vector<int> > sorted = countingSort(A);
    
    for(auto e : sorted){
        if(!e.empty()){
            for(auto x : e ){
                if(x < (total/2)){
                    cout << "- ";
                }else{
                    cout << A[x].second << " ";
                }
            }
        }
    }
        
    
    return 0;
}

