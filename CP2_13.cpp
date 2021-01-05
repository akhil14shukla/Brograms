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

unordered_map<int, vector<int>> m;

void dfs(vector<vector<int>> &v, unordered_map<int, vector<int>> &m, vector<bool> &set, vector<vector<int>> &final, const int &k, int last, int curr, int &flag, int alt)
{
    v[alt].pb(curr);
    set[curr] = true;
    final[1].pb(curr);
    if (flag)
    {
        return;
    }
    rep(j, m[curr].size())
    {
        if (set[m[curr][j]] == true && m[curr][j] != last)
        {
            vector<int> h1 = final[1];
            int h = 0;
            int mx = 0;
            for(h = 0;h<final.size();h++){
                if(final[1][h] == m[curr][j]){
                    mx = max(mx,h);
                }
            }
            if(mx>0)
            h1.erase(h1.begin(),h1.begin()+mx-1);
            if(final[0].size() == 0 || final[0].size()>h1.size() && h1.size()>2){
                final[0] = h1;
            }
            flag = 1;
        }
    }
            if (flag)
        {
            return;
        }

    rep(j, m[curr].size())
    {
        if (m[curr][j] != last && set[m[curr][j]] == false)
        {
            dfs(v, m, set, final, k, curr, m[curr][j], flag, !alt);
            if (flag)
            {
                return;
            }
        }
    }

    if (flag)
    {
        return;
    }
    set[curr] = false;
    final[1].pop_back();
    return;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v;
    v.pb({});
    v.pb({});
    int n, e, k;
    cin >> n >> e >> k;
    int f = ceil(double(k) / double(2));
    rep(i, e)
    {
        int t, x;
        cin >> t >> x;
        m[t].pb(x);
        m[x].pb(t);
    }
    int flag = 0;
    vector<vector<int>> final;
    vector<bool> set2(n + 1, false);
    final.pb({});
    final.pb({});
    dfs(v, m, set2, final, k, -1, 1, flag, 1);

    if (final[0].size() > k)
    {
        cout << 1 << el;
        int k = 0;
        rep(i, f)
        {
            cout << final[0][k] << " ";
            k = k + 2;
        }
        return 0;
    }
    else if (final[0].size() == 0)
    {
        if (v[0].size() < v[1].size())
        {
            swap(v[0], v[1]);
        }
        cout << 1 << el;
        rep(i, f)
        {
            cout << v[0][i] << " ";
        }
        return 0;
    }
    else if (final[0].size() <= k && final[0].size() > 2)
    {
        cout << 2 << el;
        cout << final[0].size() << el;
        rep(k, final[0].size())
                cout
            << final[0][k] << " ";
        return 0;
    }
}