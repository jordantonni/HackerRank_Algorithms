// https://www.hackerrank.com/challenges/recursive-digit-sum/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int superDigit(string str)
{
    if(str.length() <= 1)
        return std::stoi(str);
    
    int sd = 0;
    for(const auto c : str)
        sd += c - '0';
    
    return superDigit(to_string(sd));
}

int main() 
{
    string n, p;
    int k;
    cin >> n >> k;
    
    if(k % 10 != 0){
        while(k--)
            p += n;
    }
    else
        p += n;
    
    cout << superDigit(p);
    
    return 0;
}

