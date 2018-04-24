// https://www.hackerrank.com/challenges/priyanka-and-toys/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    int n;
    cin >> n;
    vector<int> toys;
    while(n--){
        int w;
        cin >> w;
        toys.push_back(w);
    }
    
    sort(begin(toys), end(toys));
    
    int sRange{toys[0]};
    size_t coins{1};
    for(int i=1; i<toys.size(); ++i){
        if(toys[i] > sRange+4){
            sRange = toys[i];
            ++coins;
        }
    }
    
    cout << coins << endl;
    return 0;
}

