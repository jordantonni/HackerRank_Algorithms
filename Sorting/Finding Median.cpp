// https://www.hackerrank.com/challenges/find-the-median
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int partition(vector<int>& a, int lo, int hi)
{
    int p = a[hi];
    int j = lo - 1; 
    
    for(int i = lo; i < hi; ++i)
    {
        if(a[i] < p){
            swap(a[i], a[++j]);
        }
    }
    
    if(a[hi] < a[j+1])
    {
        swap(a[hi], a[j+1]);
    }
    
    return j+1;
}

int quickSelect(vector<int>& a, int lo, int hi, int k)
{
    int p = partition(a, lo, hi);

    if(p == k-1)
        return a[p];
    else if(p > k-1)
        return quickSelect(a, lo, p-1, k);
    else
        return quickSelect(a, p+1, hi, k);
}



int main() {
    int n;
    cin >> n;
    int m = n;
    vector<int> nums;
    while(n--){
        int val;
        cin >> val;
        nums.push_back(val);
    }

    int med = quickSelect(nums, 0, nums.size() - 1, ceil(static_cast<float>(m) / 2));
    
   
    
    cout << med << endl;

    
    return 0;
}

