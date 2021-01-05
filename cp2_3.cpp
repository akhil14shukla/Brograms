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

int main()
{
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> A(2, vector<int>(n));
        rep(i, 2)
        {
            rep(j, n)
            {
                int temp;
                cin >> temp;
                A[i][j] = temp;
            }
        }
        unordered_map<int, int> m;
        int master = 0;
        rep(i, 2)
        {
            rep(j, n)
            {
                m[A[i][j]]++;
                if (m[A[i][j]] > 2)
                {
                    cout << -1 << endl;
                    master = 1;
                    break;
                }
            }
        }
        if (master)
        {
            continue;
        }
        vector<int> final;
        int count = 0;
        int flag = 1;
        m.clear();
        rep(j, n)
        {
            m[A[0][j]]++;
            if (m[A[0][j]] >= 2)
            {
                m[A[0][j]] = 1;
                int temp;
                temp = A[0][j];
                A[0][j] = A[1][j];
                A[1][j] = temp;
                final.push_back(j + 1);
                m[A[0][j]]++;
                j--;
                count++;
            }
            if (count > n)
            {
                flag = 0;
                cout << -1 << endl;
                break;
            }
        }
        if (flag)
        {
            cout << final.size() << endl;
            rep(i, final.size())
            {
                cout << final[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
