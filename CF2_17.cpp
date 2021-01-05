#include <bits/stdc++.h>
using namespace std;
#define ll long long
// #define in int
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
// vector<int> dp(2 * 10e5 + 1, -1);

int main()
{

    int t2;
    cin >> t2;
    while (t2--)
    {
        // int n;
        // cin >> n;
        ll cit, popu;
        cin >> cit >> popu;
        unordered_map<ll, ll> m;
        for (ll i = 0; i < cit; i++)
        {
            ll t;
            cin >> t;
            m[i + 1] = t;
        }
        unordered_map<ll, ll> m2;
        for (ll i = 0; i < cit; i++)
        {
            ll t;
            cin >> t;
            m2[i + 1] = t;
        }
        unordered_map<ll, ll> m3;
        vector<vector<ll>> adj(cit + 1, vector<ll>(cit + 1, 0));
        for (ll i = 0; i < cit - 1; i++)
        {
            ll x, y;
            cin >> x >> y;
            adj[x][y] = 1;
            adj[y][x] = 1;
        }
        for (ll i = cit; i >= 1; i--)
        {
            // m3[i] = m2[i];
            for (ll j = cit; j >= i + 1; j--)
            {
                if (adj[i][j] == 1)
                {
                    m[i] = m[i] + m[j];
                }
            }
        }
        for (ll i = cit; i >= 1; i--)
        {
            // m3[i] = m2[i];
            for (ll j = cit; j >= i + 1; j--)
            {
                if (adj[i][j] == 1)
                {
                    m3[i] = m3[i] + (m2[j] + m[j]) / 2;
                }
            }
        }
        int flag = 1;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if ((m2[it->first] + it->second) / 2 > it->second || (m2[it->first] + it->second) / 2 < 0 || abs(m2[it->first] - it->second) % 2 == 1 || (m3.find(it->first) != m3.end() && (m2[it->first] + m[it->first]) / 2 < m3[it->first]))
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}