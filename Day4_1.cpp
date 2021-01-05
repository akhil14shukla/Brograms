#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

int pow(int x, int n, int d)
{
if(x == 0){
    return 0;
}
if(n == 0){
    return 1%d;
}
if(n==1){
    return (x%d>0)?(x%d):(x%d+d);
}
long long final = 1;
int64_t i = x;
while(n>0){
    if(n%2 == 0){
    final = (((i*i)%d)*final)%d;
    n = n/2-1;
    i = (i*i)%d;
    }
    else{
        final = (final*i)%d;
        n =n-1;
    }
}
    if(final%d<0){
        return (final%d + d);
    }
    return final%d;
}

int main()
{
    vector<vector<int>> a2 = {
        {2, 9, 12, 13, 16, 18, 18, 19, 20, 22}, {29, 59, 62, 66, 71, 75, 77, 79, 97, 99}};

    cout << pow(71045970,41535484,64735492);
    return 0;
}
