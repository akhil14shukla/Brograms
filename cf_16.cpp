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

ll dfs(unordered_map<int, vector<int>> &tree, ll a, ll &b, vector<bool> &check, ll min1)
{
    for (int i = 0; i < tree[a].size(); i++)
    {
        if (tree[a][i] == b)
        {
            return min1 + 1;
        }
        else if (!check[tree[a][i]])
        {
            check[tree[a][i]] = true;
            ll temp = dfs(tree, tree[a][i], b, check, min1 + 1);
            if (temp != -1)
            {
                return temp;
            }
            check[tree[a][i]] = false;
        }
    }
    return -1;
}

ll fdist(unordered_map<int, vector<int>> &tree, int cur, int las, ll &final)
{
    vector<ll> th = {1};
    for (int i = 0; i < tree[cur].size(); i++)
    {
        if (tree[cur][i] != las)
        {
            th.push_back(fdist(tree, tree[cur][i], cur, final) + 1);
        }
    }
    sort(th.begin(), th.end());
    if (th.size() > 2)
        final = max(final, th[th.size() - 1] + th[th.size() - 2] - 1);
    else
        final = max(final, th[th.size() - 1]);
    return th[th.size() - 1];
}

int solve()
{
    ll n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    unordered_map<int, vector<int>> tree;
    rep(i, n - 1)
    {
        ll t1, t2;
        cin >> t1 >> t2;
        tree[t1].push_back(t2);
        tree[t2].push_back(t1);
    }
    vector<bool> check(n + 1, false);
    check[a] = true;
    ll min1 = dfs(tree, a, b, check, 0);

    ll final = 0;
    fdist(tree, a, -1, final);

    if (min1 <= da)
    {
        cout << "Alice" << endl;
        return 0;
    }
    else if (final <= 2 * da)
    {
        cout << "Alice" << endl;
        return 0;
    }
    else if (db > 2 * da)
    {
        cout << "Bob" << endl;
        return 0;
    }
    else if (2 * da >= db)
    {
        cout << "Alice" << endl;
        return 0;
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
