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

int solve()
{
    ll n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<vector<pair<int, int>>> dp(2, vector<pair<int, int>>(n, {INF, INF}));
    if (a[0] == 1)
    {
        dp[0][0] = {1, 1};
    }
    else
    {
        dp[0][0] = {0, 1};
    }
    rep2(i, 1, n - 1)
    {
        rep(j, 2)
        {
            rep(k, 2)
            {
                if(i == 1 && k == 1){
                    continue;
                }
                if (j == 0)
                {
                    if ((dp[k][i - 1].second == 2 && k == 1) || (dp[k][i - 1].second != 2))
                    {
                        if (dp[j][i].first > dp[k][i - 1].first + (!j)*a[i])
                        {
                            dp[j][i].first = dp[k][i - 1].first + (!j)*a[i];
                            if(k == 1){
                                dp[j][i].second = 1;
                            }
                            else{
                                dp[j][i].second = dp[k][i-1].second+1;
                            }
                        }
                    }
                }
                else
                {
                    if ((dp[k][i - 1].second == 2 && k == 0) || (dp[k][i - 1].second != 2))
                    {
                        if (dp[j][i].first > dp[k][i - 1].first)
                        {
                            dp[j][i].first = dp[k][i - 1].first;
                            if(k == 0){
                                dp[j][i].second = 1;
                            }
                            else{
                                dp[j][i].second = dp[k][i-1].second+1;
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<min(dp[0][n-1].first, dp[1][n-1].first)<<endl;
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
