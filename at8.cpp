#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
// #define pop pop_back
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
#define vpair vector<pair<int, int>>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fir first
#define sec second
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
#define fs fastscan

#define vrep(vec) for (const auto &value : vec)
#define arep(arrat) for (const auto &value : array)
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//over

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

ll dfs(ll n, vector<vector<ll>> &adj, vector<ll> &dp)
{
    for (ll j = 0; j < adj[n].size(); j++)
    {
        if (dp[adj[n][j]] == -1)
        {
            if (dp[n] == -1)
            {
                dp[n] = 0;
            }
            dp[n] = max(dp[n], 1 + dfs(adj[n][j], adj, dp));
        }
        else
        {
            if (dp[n] == -1)
            {
                dp[n] = 0;
            }
            dp[n] = max(dp[n], 1 + dp[adj[n][j]]);
        }
    }
    if (dp[n] == -1)
    {
        return dp[n] = 0;
    }
    return dp[n];
}
int rec(int i, int A, int B, int C)
{
    if (A == 9 && B == 9 && C == 9)
    {
        return 0;
    }
    if (i > A && i > B && i > C)
    {
        return 0;
    }
    int f1 = INT_MAX, f2 = INT_MAX, f3 = INT_MAX;
    if (A - i >= 0)
    {
        f1 = 1 + min(rec(i + 1, A - i, B + i, C), rec(i + 1, A - i, B, C + i));
        cout << i << endl;
    }
    if (B - i >= 0)
    {
        f2 = 1 + rec(i + 1, A + i, B - i, C);
    }
    if (C - i >= 0)
    {
        f3 = 1 + rec(i + 1, A + i, B, C - i);
    }
    return min(f1, min(f2, f3));
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    {
        int n, k;
        cin >> n >> k;
        vector<int> A(n);
        rep(i, n)
        {
            cin >> A[i];
        }
        vector<vector<int>> dp(2,vector<int>(k+1,0));
        int min1 = *min_element(A.begin(),A.end());
        for(int i = 0;i<min1;i++){
            dp[1][i] = 1;
        }
        for(int i = min1;i<=k;i++){
            for(int j = 0;j<A.size();j++){
                if(i - A[j]>=0){
                    dp[0][i] = max(dp[1][i - A[j]],dp[0][i]);
                    dp[1][i] = !dp[0][i];
                }
            }
        }
        if(dp[0][k]){
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }

    }
    return 0;
}