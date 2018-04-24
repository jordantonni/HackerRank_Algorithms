// https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
// Jordan Tonni
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<string> generateSubstrings(const string& str)
{
    vector<string> substrings;

    for (int i = 0; i < str.length(); ++i)
    {
        for (int j = 1; j < (str.length() - i) + 1; ++j)
        {
            substrings.push_back(str.substr(i, j));
        }
    }

    for (int i = 0; i < substrings.size(); ++i)
    {
        sort(begin(substrings[i]), end(substrings[i]));
    }

    return substrings;
}

unordered_map<string, int> makeSubstringMap(const vector<string>& substrings)
{
    unordered_map<string, int> substringMap;

    for (int i = 0; i < substrings.size(); ++i)
    {
        auto search = substringMap.find(substrings[i]);
        if (search != end(substringMap))
        {
            ++(search->second);
        }
        else
        {
            substringMap.insert(make_pair(substrings.at(i), 0));
        }
    }

    return substringMap;
}


int main()
{
    int N;
    cin >> N;

    while (N--)
    {
        string s;
        cin >> s;
        auto map = makeSubstringMap(generateSubstrings(s));

        int num = 0;

        for (auto e : map)
        {
            int realVal = e.second + 1;
            if (realVal >= 2)
            {
                num += (realVal * (realVal - 1)) / 2;
            }
            else
                num += e.second;
        }
        
        cout << num << endl;
    }
    
    return 0;
}



