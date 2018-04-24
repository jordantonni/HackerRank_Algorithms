// https://www.hackerrank.com/challenges/the-power-sum/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int target;
int expn;

int solve(int sum, int i)
{
    int newSum = sum + pow(i,expn);
    
    if(newSum == target)
        return 1;
    if(newSum > target)
        return 0;
    
    return solve(newSum, i+1)
            +
           solve(sum, i+1);
}

int getPowerSum(int total, int base)
{
    int newTotal = total - pow(base, expn);

    // Hit target +1 to number of ways
    if(newTotal == 0)
        return 1;

    // Went over the total, don't i as a part of this solution tree
    if(newTotal < 0)
        return 0;

    return getPowerSum(newTotal, base + 1) // Keep exploring using i as part of solution
           +
           getPowerSum(total, base + 1);  // Keep exploring not using i as part of solution
}

int main() 
{
    cin >> target;
    cin >> expn;
    cout << solve(0,1) << endl;
    //cout << getPowerSum(target, 1) << endl;
    
    return 0;
}

