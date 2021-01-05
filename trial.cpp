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
    if (a.first < b.first)
    {
        return 1;
    }
    else if (a.first == b.first)
    {
        if (a.second > b.second)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}
bool sortinrev2(pair<ll, ll> a,
                pair<ll, ll> b)
{
    return a.second > b.second;
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
int count = 0;
void solve()
{
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, int>> a(n);
    rep(i, n)
    {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    vector<pair<ll, pair<int, int>>> ult;
    rep(i, n)
    {
        rep2(j, i + 1, n - 1)
        {
            ult.push_back({a[i].first + a[j].first, {a[i].second, a[j].second}});
        }
    }
    sort(begin(ult), end(ult));
    ;

    // ll sum1 = a[i];
    int j = 0;
    int k = ult.size() - 1;
    while (j < k)
    {
        if (ult[j].first + ult[k].first > x)
        {
            k--;
        }
        else if (ult[j].first + ult[k].first < x)
        {
            j++;
        }
        else if (ult[j].first + ult[k].first == x && ult[j].second.second != ult[k].second.second && ult[j].second.second != ult[k].second.first && ult[j].second.first != ult[k].second.second && ult[j].second.first != ult[k].second.first)
        {
            cout << ult[j].second.first << " " << ult[j].second.second << " " << ult[k].second.first << " " << ult[k].second.second;
            return;
        }
        else
        {
            j++;
        }
    }
    cout << "IMPOSSIBLE";
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
