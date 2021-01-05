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
#define mod (int)(1e9 + 7)
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
    int n;
    cin >> n;
    vector<int> a(n);
    int ce = 0;
    int co = 0;
    rep(i, n)
    {
        cin >> a[i];
        if (a[i] == 1)
        {
            ce++;
        }
        else
        {
            co++;
        }
    }
    if (ce < co)
    {
        cout << co << endl;
        rep(i, n)
        {
            if (a[i] == 0)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }
    else if (co < ce)
    {
        // cout << n / 2 << endl;
        // int count = 0;
        // rep(i, n)
        // {
        //     if (count >= n / 2 && count%2 == 0)
        //     {
        //         break;
        //     }
        //     if (a[i] == 1)
        //     {
        //         cout << a[i] << " ";
        //         count++;
        //         if (count >= n / 2 && count%2 == 0)
        //         {
        //             break;
        //         }
        //     }
        // }
        int t = n/2;
        if(t%2 == 1){
            cout<<t + 1<<endl;
            rep(i,t+1){
                cout<<1<<" ";
            }
        }
        else{
            cout<<t<<endl;
            rep(i,t){
                cout<<1<<" ";
            }
        }
        cout << endl;
    }
    else
    {
        cout << ce << endl;
        rep(i, n)
        {
            if (a[i] == 0)
            {
                cout << a[i] << " ";
            }
        }
        cout << endl;
    }

    // vector<int> pre(n), suf(n);
    // pre[0] = 0;
    // rep2(i, 1, n - 1)
    // {
    //     if (i % 2 == 0)
    //     {
    //         pre[i] = a[i - 1] + pre[i - 1];
    //     }
    //     else
    //     {
    //         pre[i] = pre[i - 1] - a[i - 1];
    //     }

    //     if (i >= n / 2 && pre[i] == 0)
    //     {
    //         cout << i << endl;
    //         rep(j, i)
    //         {
    //             cout << a[j] << " ";
    //         }
    //         cout << endl;
    //         return 0;
    //     }
    // }
    // suf[n - 1] = 0;
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     if (i % 2 == 0)
    //     {
    //         suf[i] = a[i + 1] + suf[i + 1];
    //     }
    //     else
    //     {
    //         suf[i] = suf[i + 1] - a[i + 1];
    //     }
    //     if (i < n / 2 && suf[i] == 0)
    //     {
    //         cout << n - i - 1 << endl;
    //         for (int j = n - 1; j > i; j--)
    //         {
    //             cout << a[j] << " ";
    //         }
    //         cout << endl;
    //         return 0;
    //     }
    // }
    // rep(i, n)
    // {
    //     if (pre[i] == suf[i])
    //     {
    //         a.erase(a.begin() + i);
    //         cout << a.size() << endl;
    //         rep(i, a.size())
    //         {
    //             cout << a[i] << " ";
    //         }
    //         break;
    //     }
    // }

    // cout << n - abs(ce - co) << endl;
    // rep(i, n)
    // {
    //     if (a[i] == 0)
    //     {
    //         cout << a[i] << " ";
    //     }
    //     else if (ce > co && a[i] == 1 && i % 2 == 0)
    //     {
    //         ce--;
    //         int temp = ce;
    //         ce = co;
    //         co = temp;
    //     }
    //     else if (co > ce && a[i] == 1 && i % 2 == 1)
    //     {
    //         co--;
    //         int temp = co;
    //         co = ce;
    //         ce
    //     }
    //     else
    //     {
    //         cout << a[i] << " ";
    //     }
    // }
    // cout << endl;

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
