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
// void fun(ll &fans, vector<ll> a, int s, int e){
//       ll mini = 0;
//     ll min2 = INF;
//     rep(i,n){
//         if(min2>a[i]){
//             min2 = a[i];
//             mini = i;
//         }
//     }
//     ll fans = 0;
//     for(int i = mini+1;i<n;i++){
//         fans += (a[i] - min2)/a[mini];
//     }
// }

int solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    vector<ll> fi;
    // for(int i = 0;i<n/2;i++){
    //     ll min1 = *min_element(a.begin() + i , a.begin()+n-i);
    //     fi.push_back(min1);
    // }
    fi.push_back(-1);
    for (int k = 2; k <= n - 1; k++)
    {
        fi.push_back(INF);
        int bflag = 0;
        for (int i = 0; i < k; i++)
        {
            int m = i;
            int flag = 0;
            for (int j = m+1; j <= m + k && j < n; j++)
            {
                if (a[j] == a[i])
                {
                    m = j;
                }
                if (m + k >= n - 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag){
            fi.back() = min(fi.back(), a[i]);
            bflag =  1;
            }
        }
        if(!bflag){
            fi.back() = -1;
        }
    }
    rep(i,fi.size()){
        cout<<fi[i]<<" ";
    }
    cout<<endl;
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
