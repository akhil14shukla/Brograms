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
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    if (a.first < b.first)
    {
        return 1;
    }
    else if (a.first == b.first)
    {
        if (a.second < b.second)
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
bool count(vector<ll> &a, ll &mid, ll &x)
{
    ll sum = 0, groups = 0;
    for (int i = 0; i < int(a.size()); i++)
    {
        if (a[i] > mid)
        {
            return false;
        }
        if (sum + a[i] > mid)
        {
            groups++;
            sum = 0;
        }
        sum += a[i];
    }
    if (sum > 0)
    {
        groups++;
    }
    return groups <= x;
}
struct ordered_multiset
{ // multiset supporting duplicating values in set
    ll len = 0;
    const ll ADD = 1000010;
    const ll MAXVAL = 1000000010;
    unordered_map<ll, ll> mp; // hash = 96814
    tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> T;

    ordered_multiset()
    {
        len = 0;
        T.clear(), mp.clear();
    }

    inline void insert(ll x)
    {
        len++, x += MAXVAL;
        ll c = mp[x]++;
        T.insert((x * ADD) + c);
    }

    inline void erase(ll x)
    {
        x += MAXVAL;
        ll c = mp[x];
        if (c)
        {
            c--, mp[x]--, len--;
            T.erase((x * ADD) + c);
        }
    }

    inline ll kth(ll k)
    { // 1-based index,  returns the
        if (k < 1 || k > len)
            return -1;                  // K'th element in the treap,
        auto it = T.find_by_order(--k); // -1 if none exists
        return ((*it) / ADD) - MAXVAL;
    }

    inline ll lower_bound(ll x)
    { // Count of value <x in treap
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x * ADD) + c));
    }

    inline ll upper_bound(ll x)
    { // Count of value <=x in treap
        x += MAXVAL;
        ll c = mp[x];
        return (T.order_of_key((x * ADD) + c));
    }

    inline int size() { return len; } // Number of elements in treap
};
void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<pair<ll, ll>> b(m);
    rep(i, n)
    {
        cin >> a[i];
    }
    multiset<pair<ll, ll>> ms;
    rep(i, m)
    {
        int x, t;
        cin >> x >> t;
        ms.insert({x + t, x - t});
    }
    sort(begin(a), end(a));
    // sort(begin(b),end(b));
    ll count = 0, j = 0;
    ;
    rep(i, n)
    {
        auto it = ms.lower_bound({a[i],-1e9});
        while(it!=ms.end()&& it->second>a[i] &&it->first >= a[i]){
            it = next(it);
        }
        if(it!=ms.end()&& it->second<=a[i] && it->first >= a[i]){
            count++;
            ms.erase(it);
        }
    }
    cout << count;
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
