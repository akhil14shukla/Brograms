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

// string trans(string A, int d){
// }

int max1(string A)
{
    int t = 0;
    rep(i, A.size())
    {
        t = max(t, A[i] - '0');
    }
    return t;
}
int min1(string A)
{
    int t = 12;
    rep(i, A.size())
    {
        t = min(t, A[i] - '0');
    }
    return t;
}

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //use auto instead of data types
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        unordered_map<int,int> m;
        int j = 1;
        rep(i, n)
        {
            cin >> A[i];
            if(m.find(A[i]) == m.end()){
                m[A[i]] = j;
                j++;
            }
        }
        cout<<j-1<<endl;
        rep(i,n){
            cout<<m[A[i]]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
