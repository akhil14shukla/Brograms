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
#define mod (int)1e9 + 7
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
ll modu(ll n, ll d)
{
    ll qw = n % d;
    if (qw < 0)
    {
        return qw + d;
    }
    return qw;
}
ll solve()
{
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
        if (i != 0)
            a[i] += a[i - 1];

        a[i] = modu(a[i], h);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (modu(a[i - 1] - j, h) >= l && modu(a[i - 1] - j, h) <= r)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            }
            // if (modu(a[i - 1] - j - 2, h) >= l && modu(a[i - 1] - j - 2, h) <= r && j>0)
            // {
            //     dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            // }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            // if(j>0){
            //     dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
            // }
        }
    }
    int count = 0;
    for (int i = 0; i <= n; i++)
    {
        count = max(count, dp[n][i]);
    }
    cout << count << endl;
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
        solve();
    }

    return 0;
}
