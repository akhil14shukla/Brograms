#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
// #define pop pop_back
#define ll unsigned long long int
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

int dfs(int n, vector<vector<int>> &adj, vector<bool> &check, vector<vector<ll>> &final1, int last)
{
    // if (n == target)
    // {
    //     check[target] = true;
    //     return final;
    // }
    for (int j = 0; j < adj[last].size(); j++)
    {
        if (adj[last][j] != 0 && !check[j])
        {
            check[j] = true;
            final1[n][j] = final1[n][last] + adj[last][j];
            dfs(n, adj, check, final1, j);
        }
        // if (check[target])
        // {
        //     return a;
        // }
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    // int t;
    // cin >> t;
    // while (t--)
    {
        ll n, c;
        cin >> n >> c;
        vector<ll> a(n);
        rep(i, n)
        {
            cin >> a[i];
        }
        vector<ll> dp(n, 0);
        for (int i = 1; i < n; i++)
        {
            //  dp[i] = dp[0] + abs(a[i] - a[0]);
            dp[i] = INT_MAX;
            for (int x = 0; x < i; x++)
            {
                dp[i] = min(dp[i], dp[x] + (a[i] - a[x])*(a[i] - a[x]) + c);
            }
            // if(i>=2){
            //  dp[i] = min(dp[i-1] + abs(a[i] - a[i-1]),dp[i-2] + abs(a[i] - a[i-2]));
            // }
            // else{
            //     dp[i] = dp[i-1] + abs(a[i] - a[i-1]);
            // }
        }
        cout << dp[n - 1] << endl;
    }
    return 0;
}
