#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
#define pop pop_back
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
pair<long, int> max1(vvl a, int k, vector<bool> &check)
{
    long max2 = 0;
    int last = 0;
    for (int i = 0; i <= a.size() - 1; i++)
    {
        if (!check[i])
        {
            if (max2 < a[i][k])
            {
                max2 = a[i][k];
                last = i;
            }
        }
    }
    check[last] = true;
    return {max2, last};
}
long rec(vector<int> dp, vvl a, vector<bool> check, int k)
{
    long final = 0;
    if (k < a[0].size())
    {
        pair<long, int> temp = max1(a, k, check);
        // pair<long, int> mark2 = max1(a, i, check);
        final = max(final, temp.first);
        check[temp.second] = false;
    }
    if (k > 0)
    {
        for (int i = 1; i < k; i++)
        {
            // if (k < a[0].size())
            {
                pair<long, int> mark1 = max1(a, k - i, check);
                pair<long, int> mark2 = max1(a, i, check);
                final = max(final, mark1.first + mark2.first);
                check[mark1.second] = false;
                check[mark2.second] = false;
            }
        }
    }
    return final;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;
    int l = 0;
    while (l != t)
    {
        int n, k, p;
        cin >> n >> k >> p;
        vvl a(n + 1, vl(k + 1, 0));
        rep(i, n)
        {
            rep(j, k)
            {
                ll t;
                cin >> t;
                a[i + 1][j + 1] = t + a[i + 1][j];
            }
        }
        vvl dp(n + 1, vl(p + 1, 0));
        for (int i = 0; i <= k && i <= p; i++)
        {
            dp[1][i] = a[1][i];
        }
        rep2(i, 1, n)
        {
            rep2(j, 0, p)
            {
                for (int z = 0; z <= j && z <= k; z++)
                {
                    dp[i][j] = max(a[i][z] + dp[i-1][j-z],dp[i][j]);
                }
            }
        }
        cout <<"Case #"<<l+1<<": "<<dp[n][p] << endl;
        l++;
    }

    return 0;
}
