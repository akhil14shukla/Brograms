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

pair<int, int> func(int x, int y, int flag, vector<vector<bool>> &ch)
{
    if (flag)
    {
        int lx = x, ly = y;
        for (int i = x; i >= 0; i--)
        {
            if (!ch[i][y])
            {
                cout << i + 1 << " " << y + 1 << endl;
                ch[i][y] = true;
                lx = i;
                ly = y;
            }
        }
        for (int i = x + 1; i < ch.size(); i++)
        {
            if (!ch[i][y])
            {
                cout << i + 1 << " " << y + 1 << endl;
                ch[i][y] = true;
                lx = i;
                ly = y;
            }
        }
        return {lx, ly};
    }
    else
    {
        int lx = x, ly = y;
        for (int i = y; i >= 0; i--)
        {
            if (!ch[x][i])
            {
                cout << x + 1 << " " << i + 1 << endl;
                ch[x][i] = true;
                lx = x;
                ly = i;
            }
        }
        for (int i = y + 1; i < ch[0].size(); i++)
        {
            if (!ch[x][i])
            {
                cout << x + 1 << " " << i + 1 << endl;
                ch[x][i] = true;
                lx = x;
                ly = i;
            }
        }
        return {lx, ly};
    }
}

int solve()
{
    int n,d,m;
    cin>>n>>d>>m;
    vector<int> A(n);
    rep(i,n){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    long final = A[n-1];
    int i = 0,j=n-1;
    while(j>i){
        long sm = 0;
        for(int k = 0;k<=d;k++){
            sm += A[k];
        }
    }
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
