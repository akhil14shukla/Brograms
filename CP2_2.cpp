#include <iostream>
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

bool sortinrev(const int &a, const int &b)
{
    return (a > b);
}

int rec(char a, string s, int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        if (s[0] != a)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int count1 = 0;
    int count2 = 0;
    int check = 0;
    rep(i, n / 2)
    {
        if (s[i] != a)
        {
            check = 1;
        }
        else
        {
            count1++;
        }
    }
    for (int i = n - 1; i >= n / 2; i--)
    {
        if (s[i] != a)
        {
            if (check)
            {
                check = 2;
            }
            else
            {
                check = 1;
            }
        }
        else
        {
            count2++;
        }
    }
    return min(n / 2 - count1 + rec(a + 1, s.substr(n / 2, n / 2), n / 2), n / 2 - count2 + rec(a + 1, s.substr(0, n / 2), n / 2));
}

int main()
{
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << rec('a', s, n) << endl;
    }
    return 0;
}
