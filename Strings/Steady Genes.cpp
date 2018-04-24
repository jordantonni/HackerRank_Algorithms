// https://www.hackerrank.com/challenges/bear-and-steady-gene/problem
// Jordan Tonni

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;

string readIn()
{
    int n;
    cin >> n;
    string s;
    cin.ignore();
    getline(cin, s);
    return s;
}

bool valid(const unordered_map<char,int>& freq, const int correct)
{
    for(const auto cnt : freq)
        if(cnt.second > correct)
            return false;

    return true;
}

int main()
{
    string str = readIn();
    unordered_map<char,int> freq;
    priority_queue<int, vector<int>, greater<int>> lengths;
    int min = str.length() / 4;

    for(const auto c : str)
        ++freq[c];

    for(int i = 0, j = 0; i < str.length(); ++i){
        while(j < str.length() && !valid(freq, min)){
            --freq[str[j]];
            ++j;
        }
        if(valid(freq, min))
            lengths.push(j - i);

        ++freq[str[i]];
    }

    cout << lengths.top() << endl;
    return 0;
}



