// https://www.hackerrank.com/challenges/caesar-cipher-1/problem
// Jordan Tonni


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void lowerCaseRotate(string& s, int index, int k)
{
    char c = s.at(index);
    int relativePosition = c - 'a';
    int newChar = (relativePosition + k) % 26;
    s[index] = static_cast<char>('a' + newChar);
}
void upperCaseRotate(string& s, int index, int k)
{
    char c = s.at(index);
    int relativePosition = c - 'A';
    int newChar = (relativePosition + k) % 26;
    s[index] = static_cast<char>('A' + newChar);
}

int main() {
    int n;
    int k;
    string s;
    cin >> n >> s >> k;
    
    for(int i = 0; i < s.length(); ++i){
        char ch = s.at(i);
        
        if(ch >= 'a' && ch <= 'z')
            lowerCaseRotate(s, i, k);
        if(ch >= 'A' && ch <= 'Z')
            upperCaseRotate(s, i, k);
    }
    
    cout << s << endl;
    return 0;
}

