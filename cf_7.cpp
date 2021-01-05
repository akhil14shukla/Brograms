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
#define INF (ll)9e9 + 1
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

ll powe(ll i1, ll n)
{
    ll prod = 1;
    for (int i = 1; i <= n; i++)
    {
        prod = prod * i1;
    }
    return prod;
}

int solve()
{
    // unordered_map<char,int> m;
    int n;
    cin >> n;
    vector<int> a(n);
    // ll sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        // sum += a[i];
    }
    sort(a.begin(), a.end());
    ll lim = sqrt(a[n - 1]);
    // rep(i,n){
    //     lim = sqrt(lim);
    // }
    ll min1 = INF;
    ll num = 0;
    rep2(i, 2, lim + 2)
    {
        ll comp = powe(i, n-1);
        if (min1 > abs(comp - a[n-1]))
        {
            min1 = abs(comp - a[n-1]);
            num = i;
        }
    }
    ll count = 0;
    rep(i, n)
    {
        count += abs(a[i] - powe(num, i));
    }
    cout << count << endl;

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
