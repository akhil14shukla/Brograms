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
ll nChoosek(ll n, ll k)
{
    if (k > n)
        return 0;
    if (k * 2 > n)
        k = n - k;
    if (k == 0)
        return 1;

    ll result = n;
    for (ll i = 2; i <= k; ++i)
    {
        result *= (n - i + 1);
        result /= i;
    }
    return result;
}
inline void er(ll &ans, vector<int> &a, int l){
    if(l==0 || l==a.size()-1){
        return;
    }
    if(a[l]>a[l-1] && a[l]>a[l+1]){
        ans-= a[l];
    }
    if(a[l]<a[l-1] && a[l]<a[l+1]){
        ans += a[l];
    }
}

inline void in(ll &ans, vector<int> &a, int l){
    if(l==0 || l==a.size()-1){
        return;
    }
    if(a[l]>a[l-1] && a[l]>a[l+1]){
        ans+= a[l];
    }
    if(a[l]<a[l-1] && a[l]<a[l+1]){
        ans -= a[l];
    }
}

int solve()
{
    ll n, q;
    cin >> n >> q;
    vector<int> a(n + 2);
    rep2(i, 1, n)
    {
        cin >> a[i];
    }
    a[0] = a[n + 1] = -1;
    ll ans = 0;
    int x = 0;
    int last = 0;
    rep2(i, 1, n)
    {
        if (!x)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                ans += a[i];
                x = 1;
                last = 0;
            }
        }
        else
        {
            if (a[i] < a[i - 1] && a[i] < a[i + 1])
            {
                ans -= a[i];
                x = 0;
                last = i;
            }
        }
    }
    // if (!last)
    // {
    //     ans += a[n - 1];
    // }
    cout << ans << endl;
    while(q--){
        ll l,r;
        cin>>l>>r;
        if(l == r){
            cout<<ans<<endl;
            continue;
        }
        er(ans,a,l-1);
        er(ans,a,l);
        er(ans,a,l+1);
        if(r-l == 1){
            er(ans,a,r+1);
        }
        else if(r-l == 2){
            er(ans,a,r);
            er(ans,a,r+1);
        }
        else{
            er(ans,a,r-1);
            er(ans,a,r);
            er(ans,a,r+1);
        }
        swap(a[l],a[r]);
        in(ans,a,l-1);
        in(ans,a,l);
        in(ans,a,l+1);

        if(r-l == 1){
            in(ans,a,r+1);
        }
        else if(r-l == 2){
            in(ans,a,r);
            in(ans,a,r+1);
        }
        else{
            in(ans,a,r-1);
            in(ans,a,r);
            in(ans,a,r+1);
        }
        cout<<ans<<endl;
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
        continue;
    }

    return 0;
}
