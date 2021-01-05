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
#define mod (int)(1e9 + 7)
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
ll modu(ll n, ll d)
{
    ll qw = n % d;
    if (qw < 0)
    {
        return qw + d;
    }
    return qw;
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

int solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a[i][j];
        }
    }
    if (min(n, m) > 3)
    {
        cout << -1 << endl;
        return 0;
    }
    else if (min(n, m) == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> b(max(m, n), 0);
    rep(i, max(m, n))
    {
        for (int j = min(m, n) - 1; j >= 0; j--)
        {
            if (m > n)
            {
                b[i] += (a[j][i] - '0') * pow(2, n - 1 - j);
            }
            else
            {
                b[i] += (a[i][j] - '0') * pow(2, n - 1 - j);
            }
        }
    }
    unordered_map<int, unordered_set<int>> m1;
    m1[0].insert({0, 5, 2});
    m1[1].insert({1, 4, 3});
    m1[2].insert({2, 0, 7});
    m1[3].insert({3, 1, 6});
    m1[4].insert({4, 6, 1});
    m1[5].insert({5, 0, 7});
    m1[6].insert({6, 3, 4});
    m1[7].insert({7, 2, 5});

    vector<vector<int>> dp(max(m, n), vector<int>(8, INT_MAX));

    vector<vector<int>> dp1(max(m, n), vector<int>(4, INT_MAX));
    int last = b[0];
    // dp[0][b[0]] = 0;
    // dp[0][m[b[0]]];
    for (auto i = m1[b[0]].begin(); i != m1[b[0]].end() && min(m, n) == 3; i++)
    {
        dp[0][*i] = __builtin_popcount((*i) ^ b[0]);
    }

    for (auto i = m1[b[0]].begin(); i != m1[b[0]].end() && min(m, n) == 2; i++)
    {
        if (*i < 4)
        {
            dp1[0][*i] = __builtin_popcount((*i) ^ b[0]);
        }
    }

    for (int i = 1; i < max(m, n); i++)
    {
        // int min1 = INT_MAX;
        // ll store = b[i];
        // dp[i][
        for (auto j = m1[last].begin(); j != m1[last].end(); j++)
        {
            for (auto k = m1[b[i]].begin(); k != m1[b[i]].end(); k++)
            {
                if (min(m, n) == 2 && *j < 4 && *k < 4 && m1[*k].find(*j) != m1[*k].end())
                {
                    dp1[i][*j] = min(dp1[i][*j], dp1[i - 1][*k] + __builtin_popcount((*k) ^ b[i]));
                }
                else if (min(m, n) == 3 && m1[*k].find(*j) != m1[*k].end())
                {
                    dp[i][*k] = min(dp[i][*k], dp[i - 1][*j] + __builtin_popcount((*k) ^ b[i]));
                }
            }
        }
        last = b[i];
    }
    cout << *min_element(dp[max(m, n) - 1].begin(), dp[max(m, n) - 1].end()) << endl;
    // if (min(m, n) ==)
    // cout << final << endl;
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
