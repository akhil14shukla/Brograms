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
#define vpair vector<pair<long, long>>
#define mp make_pair
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second > b.second);
}

int gen(int num, int k)
{
    int fin = 0;
    for (int i = 0; i < num; i++)
    {
        fin = fin + k * pow(10, i);
    }
    return fin;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int n;
    cin >> n;
    vpair m(n);
    unordered_map<int, long long> m3;
    rep(i, n)
    {
        // int t1, t2;
        cin >> m[i].first >> m[i].second;
        // m[t2] = t1;
        m3[i] = m[i].first;
        m[i].first = i;
    }
    int s;
    cin >> s;
    vpair c(s);
    unordered_map<int, long long> m2;
    rep(i, s)
    {
        cin >> c[i].first;
        cin >> c[i].second;
        m2[i] = c[i].first;
        c[i].first = i;
    }
    sort(c.begin(), c.end(), sortinrev);
    sort(m.begin(), m.end(), sortinrev);
    vector<bool> check(n, false);
    vpair final;
    ll sum = 0;
    rep(i, s)
    {
        int t = -1;
        rep(j, n)
        {
            if ((m[j].second - c[i].second == 0 || m[j].second - c[i].second == 1) && check[m[j].first] == false)
            {
                if (m2[c[i].first] >= m3[m[j].first])
                {
                    if (t < m3[m[j].first])
                    {
                        if (t != -1)
                        {
                            check[final[final.size() - 1].second - 1] = false;
                            check[m[j].first] = true;
                            t = m3[m[j].first];
                            final.pop_back();
                            final.pb(mp(c[i].first + 1, m[j].first + 1));
                        }
                        else
                        {
                            check[m[j].first] = true;
                            t = m3[m[j].first];
                            final.pb(mp(c[i].first + 1, m[j].first + 1));
                        }
                    }
                }
                else if(m[j].second-c[i].second > 1){
                    break;
                }
            }
        }
        if (t != -1)
        {
            sum += t;
        }
    }
    cout << sum << el;
    cout << final.size() << el;
    rep(i, final.size())
    {
        cout << final[i].first << " " << final[i].second << el;
    }
    return 0;
}
