// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
// Jordan Tonni
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int indexOfMin(const vector<int>& v)
{
    int min = INT_MAX;
    int indx = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] != 0 && v[i] < min)
        {
            min = v[i];
            indx = i;
        }
    }
    return indx;
}

auto iterOfMax(const vector<int>& v)
{
    return max_element(begin(v), end(v));
}

bool check(const vector<int> v)
{
    return (v[indexOfMin(v)] == *(iterOfMax(v)));
}


int main()
{
    string s;
    cin >> s;
    bool flag = 0;
    vector<int> freq(26, 0);

    // Set freq count
    for (int i = 0; i < s.length(); ++i)
    {
        ++freq[s.at(i) % 26];
    }

    if (check(freq))
    {
        cout << "YES\n";
        return 0;
    }
    else if (freq[indexOfMin(freq)] < *(iterOfMax(freq) - 1))
    {
        cout << "NO\n";
        return 0;
    }

    vector<int> copy = freq;
    --copy[indexOfMin(copy)];

    if (check(copy))
    {
        cout << "YES\n";
        return 0;
    }

    auto max = iterOfMax(freq);
    vector<int>::iterator it = begin(freq);
    advance(it, distance<vector<int>::const_iterator>(it, max));
    --(*it);

    if (check(freq))
    {
        cout << "YES\n";
        return 0;
    }

    cout << "NO\n";
    return 0;
}
   



