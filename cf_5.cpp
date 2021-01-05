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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
        rep(i, n - 1)
        {
            int t1, t2;
            cin >> t1 >> t2;
            adj[t1][t2] = 1;
            adj[t2][t1] = 1;
        }
        int m;
        cin >> m;
        vector<int> fac(m);
        rep(i, m)
        {
            cin >> fac[i];
        }
        rep(i, n - 1 - m)
        {
            fac.push_back(1);
        }
        sort(fac.begin(), fac.end());
        int k = n - 2;
        // for (int i = n; i > 0; i--)
        // {
        //     for (int j = n; j > 0; j--)
        //     {
        //         if (adj[i][j] == -1)
        //         {
        //             adj[i][j] = fac[k];
        //             adj[j][i] = fac[k];
        //             k--;
        //         }
        //     }
        // }
        ll sum = 0;
        vector<vector<ll>> final1(n + 1, vector<ll>(n + 1, 0));
        // vector<bool> check(n + 1, false);
        rep2(i, 1, n)
        {
            // rep2(j, i + 1, n)
            // {
            queue<int> q;
            q.push(i);
            vector<bool> check(n + 1, false);
            int last = i;
            int cur = i;
            check[i] = true;
            while (!q.empty())
            {
                last = cur;
                cur = q.front();
                q.pop();
                for (int j = 0; j < adj[cur].size(); j++)
                {
                    if (adj[cur][j] != 0 && !check[j])
                    {
                        check[j] = true;
                        adj[cur][j]++;;
                        q.push(j);

                    }
                }
            }
            // sum = sum % d;
            // }
        }
        rep(i, n + 1)
        {
            rep2(j, i + 1, n)
            {
                sum += final1[i][j];
            }
        }
        cout << sum << el;
    }
    return 0;
}
