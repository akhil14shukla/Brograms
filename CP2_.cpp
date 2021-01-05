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
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
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
        int n;
        cin >> n;
        vi a(n);
        rep(i, n)
        {
            cin >> a[i];
        }
        vi final;
        final.pb(0);
        rep(i, n)
        {
            if (final.size() == 1)
            {
                if (a[i] < a[final[0]])
                {
                    final.pop_back();
                    final.pb(i);
                }
                else if (a[i] > a[final[0]])
                {
                    final.pb(i);
                }
            }
            else if (final.size() == 2)
            {
                if (a[i] > a[final[1]])
                {
                    final.pop_back();
                    final.pb(i);
                }
                else if (a[i] < a[final[1]])
                {
                    final.pb(i);
                    break;
                }
            }
        }
        if (final.size() == 3)
        {
            cout << "YES" << el;
            rep(i, 3)
            {
                cout << final[i]+1 << " ";
            }
            cout << el;
        }
        else
        {
            cout << "NO" << el;
        }
    }
    // cout << k << el;

    return 0;
}
