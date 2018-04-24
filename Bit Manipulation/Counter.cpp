// https://www.hackerrank.com/challenges/counter-game/problem
// Jordan Tonni

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

size_t numOnes(long long n)
{
    size_t count = 0;
    while(n){
        if(n & 1)
            ++count;
        n >>= 1;
    }
    return count;
}

bool isPow2(long long n)
{
    return numOnes(n) == 1;
}

long long halfIt(long long n)
{
    return n >> 1;
}

int ms_one_bit_pos(long long n)
{
    if(!n)
        return -1;
    
    int counter = -1;
    int ms_one = -1;
    
    while(n){
        ++counter;
        if(n & 1)
            ms_one = counter;
        n >>= 1;
    }
    
    return ms_one;
}

long long closest_pow2_under(long long n)
{
    int bit_pos = ms_one_bit_pos(n);
    return (1L << bit_pos);
}

void print_winner(bool flag)
{
    if(flag)
        cout << "Richard" << endl;
    else
        cout << "Louise" << endl;
}

void take_turn(bool& flag, long long& n)
{
    flag ^= 1;
    
    if(isPow2(n))
        n = halfIt(n);
    else
        n -= closest_pow2_under(n);
}

int main() 
{
    int t;
    cin >> t;
    
    while(t--){
        long long n;
        cin >> n;
        bool flag = 1;
        
        while(n > 1)
            take_turn(flag, n);
        
        print_winner(flag);
    }
    return 0;
}

