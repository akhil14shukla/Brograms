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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '0')
        {
            c1--;
        }
        else if (s[i] == '1')
        {
            c1++;
        }
        else
        {
            c0++;
        }
    }
    if (c0 < abs(c1))
    {
        std::cout << "NO" << endl;
        return 0;
    }
    int f1 = 0, f0 = 0;
    if (c1 < 0)
    {
        f1 = -1 * c1;
    }
    else if (c1 > 0)
    {
        f0 = c1;
    }
    int free = c0 - abs(c1);
    if (free % 2)
    {
        std::cout << "NO" << endl;
        return 0;
    }
    for (int i = k; i < n; i++)
    {
        if (s[i - k] != s[i] && s[i - k] != '?' && s[i] != '?')
        {
            std::cout << "NO" << endl;
            return 0;
        }
        else if (s[i - k] == '?' && s[i] != '?')
        {
            if (s[i] == '1' && f1 > 0)
            {
                f1--;
            }
            else if (s[i] == '0' && f0 > 0)
            {
                f0--;
            }
            else if (free > 0)
            {
                free = free - 2;
                if (s[i] == '1')
                {
                    f0++;
                }
                else
                {
                    f1++;
                }
            }
            else
            {
                std::cout << "NO" << endl;
                return 0;
            }
            // free = free - 2;
        }
        else if (s[i] == '?')
        {
            if (s[i - k] == '1')
            {
                s[i] = '1';
            }
            else if (s[i - k] == '0')
            {
                s[i] = '0';
            }
            else
            {
                if (free > 0)
                {
                    continue;
                }
                else if (f1 > 0)
                {
                    s[i] = '1';
                }
                else if (f0 > 0)
                {
                    s[i] = '0';
                }
            }
        }
        //     else if(s[i - k] == s[i] && s[i - k] == '?' && s[i] == '?' ){

        //     }
        // }
    }
    std::cout << "YES" << endl;
    // cout << final << endl;
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
