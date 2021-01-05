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
    return (a.second < b.second);
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
void rec(vector<ll> &v, ll &sum, ll min, int s)
{
    if (s == v.size())
    {
        if (sum > min)
        {
            sum = min;
        }
        return;
    }
    // for (int i = s; i < v.size(); i++)
    // {
    // min += v[i];
    rec(v, sum, abs(min + v[s]), s + 1);
    rec(v, sum, abs(min - v[s]), s + 1);
    // }
}
int solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    unordered_map<ll,int> m; 
    rep(i,n){
        cin>>a[i];
        m[a[i]]++;
    }
    vector<pair<ll,ll>> f;
    unordered_map<ll,int>::iterator m1;
    for(m1 = m.begin();m1!=m.end();m1++){  
          f.push_back({m1->first,m1->second});
    }
    sort(f.begin(),f.end(),sortinrev);
    int count = 0;
    // if(a[0]!=f[0].first){
    //     count++;
    // }
    for(int i = 1;i<n;i++){
        if(a[i]==f[0].first && a[i-1]!=f[0].first){
            count++;
        }
    }
    if(a[n-1]!=f[0].first){
        count++;
    }
    int count2 = 0;
    // if(a[0]!=f[f.size()-1].first){
    //     count2++;
    // }
    for(int i = 1;i<n;i++){
        if(a[i]==f[f.size()-1].first && a[i-1]!=f[f.size()-1].first){
            count2++;
        }
    }
    if(a[n-1] != f[f.size()-1].first){
        count2++;
    }
    cout<<min(count,count2)<<endl;
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