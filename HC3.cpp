#include <iostream>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
#define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpair vector<pair<long, long>>
#define mp make_pair
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second > b.second);
}

int gen(int num, int k)
{
    int fin = 0;
    for (int i = 0; i < num; i++)
    {
        fin = fin + k * pow(10, i);
    }
    return fin;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int f;
    fstream In;
    In.open("alchemy_input.txt");
    ofstream Out("output.txt");
    In >> f;
    int l = 1;
    while (l <= f)
    {
        int n;
        In >> n;
        vector<int> P(n);
        vector<int> H(n);
        rep(i,n){
            cin>>P[i]>>H[i];
        }
        vector<pair<int,int>> dp(n);
        // dp[0] = H[0];
        for(int i = 11;i<n;i++){
            if(P[i-1] + H[i-1] == P[i]){
                
            }
        }
        {
            Out << "Case #" << l << ":"
                << " Y" << el;
        }
        else
        {
            Out << "Case #" << l << ":"
                << " N" << el;
        }
        l++;
    }
    Out.close();
    return 0;
}
