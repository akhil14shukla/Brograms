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
    return (a.second > b.second);
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
ll fact(ll n)
{
    ll res = 1;
    for (ll i = 2; i <= n; i++)
        res = res * i;
    return res;
}
void permute(unordered_map<char, ll> m, int n, int count, string t)
{
    if (count >= n)
    {
        cout << t << endl;
        return;
    }
    for (char a = 'a'; a <= 'z'; a++)
    {
        // for(int i = 0;i<m[a];i++){
        if (m[a] > 0)
        {
            t = t + a;
            m[a]--;
            permute(m, n, count + 1, t);
            t.pop_back();
            m[a]++;
        }
        // }
    }
}
void rec(vector<vector<int>> &a, int i, vector<bool> &b,int n, int &count)
{
    for(int j = 0;j<a.size();j++){
        if(!b[j] && a[i][j] == 1){
            b[j] = true;
            count += n+1;
            rec(a,j,b,n+1,count);
            b[j] = false;
        }
    }
}
int solve()
{
    ll n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n,0));
    for(int i = 0;i<n;i++){
        int x, y;
        cin>>x>>y;
        a[x-1][y-1]++;
        a[y-1][x-1]++;
    }
    int count = 0;
    vector<bool> b(n,false);
    rec(a,0,b,0,count);
    cout<<count<<endl;
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