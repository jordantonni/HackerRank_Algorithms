// https://www.hackerrank.com/challenges/sherlock-and-array/problem
// Jordan Tonni
//

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
    
    while(n--)
    {
        int l;
        cin >> l;
        vector<int> arr;
        int sum = 0;
        while(l--){
            int val;
            cin >> val;
            arr.push_back(val);
            sum += val;
        }
        
        if(arr.size() == 1)
        {
            cout << "YES" << endl;
            continue;
        }
        
        int temp_sum = sum - arr[0];
        int left_sum = arr[0];
        for(int i = 1; i < arr.size(); ++i){
            temp_sum -= arr[i];
            
            if(temp_sum == left_sum){
                break;
            }
            left_sum += arr[i];
        }
        
        if(temp_sum == left_sum){
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
        
        
    }
    
    
    return 0;
}


