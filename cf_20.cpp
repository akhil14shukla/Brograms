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
    return (a.first < b.first);
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
ll nChoosek(ll n, ll k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    ll result = n;
    for (ll i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}

int solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> pre(n), suf(n);
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    vector<pair<int, int>> p;
    unordered_set<int> s;
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        if (pre[i] == 0)
        {
            p.push_back({0, i});
            // s.insert(i);
        }
    }

    // for (int i = n - 2; i >= 0; i--)
    // {
    //     suf[i] = suf[i + 1] + a[i];
    //     p.push_back({i, n - 1});
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (pre[i] - pre[j] == 0)
            {
                p.push_back({j + 1, i});
                // s.insert(j + 1);
            }
        }
    }
    sort(p.begin(), p.end());
    vector<pair<int, int>> p2;
    for (int i = 0; i < p.size(); i++)
    {
        if (s.find(p[i].first) == s.end())
        {
            p2.push_back({p[i].first, p[i].second});
        }
    }
    p.erase(p.begin(),p.end());
    int count = 0;
    // int last = -1;
    int ul = p2[p2.size()-1].first;
    for (int i = p2.size() - 2;i>=0;i--)
    {
        if (p2[i].second > ul)
        {
            continue;
        }
        else
        {
            count++;
            ul = p2[i].first;
        }
    }
    if(p2.size() == 0){
        cout<<0<<endl;
        return 0;
    }
    cout << count+1 << endl;
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
