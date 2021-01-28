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
#define INF (ll)(2e9 + 1)
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
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n, vector<ll>(m, 0));
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> a[i][j];
        }
    }
    int l = 0, h = m - 1;
    ll elem = 2e9;
    while (l <= h && elem == 2e9)
    {
        ll mid = l + (h - l) / 2;
        ll min1 = INF;
        int ind = 0;
        for (int i = 0; i < n; i++)
        {
            if (min1 > a[i][mid])
            {
                min1 = a[i][mid];
                ind = i;
            }
        }
        if (a[ind][mid] < a[ind][mid - 1] && a[ind][mid + 1] > a[ind][mid])
        {
            elem = a[ind][mid];
        }
        if (mid - 1 >= 0 && mid + 1 < m)
        {
            if (a[ind][mid - 1] > a[ind][mid + 1])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    if (elem == INF)
        for (int i = 0; i < n; i++)
        {
            elem = min(elem,a[h][i]);
        }
    cout<<elem<<endl;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    // cin >> t;
    t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}
