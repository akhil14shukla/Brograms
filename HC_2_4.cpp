#include <bits/stdc++.h>
#define pb push_back
#define pop pop_back
#define ll int64_t
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
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //use auto instead of data types
    int f;
    fstream cin;
    cin.open("in.txt");
    ofstream Out("output.txt");
    cin >> f;
    int l = 1;
    while (l <= f)
    {
        ll n, m, k;
        cin >> n >> m;
        cin >> k;
        ll s;
        cin >> s;

        vector<ll> P(n);
        rep(i, k)
        {
            cin >> P[i];
        }
        ll Ap, Bp, Cp, Dp;
        cin >> Ap >> Bp >> Cp >> Dp;
        vector<ll> Q(n);
        rep(i, k)
        {
            cin >> Q[i];
        }
        ll Aq, Bq, Cq, Dq;
        cin >> Aq >> Bq >> Cq >> Dq;
        rep2(i, k, n - 1)
        {
            P[i] = (Ap * P[i - 2] + Bp * P[i - 1] + Cp) % Dp + 1;
        }
        rep2(i, k, m - 1)
        {
            Q[i] = (Aq * Q[i - 2] + Bq * Q[i - 1] + Cq) % Dq + 1;
        }
        ll m1 = *max_element(P.begin(),P.end());
        ll m2 = *max_element(Q.begin(),Q.end());
        ll mx = max(m1,m2);
        vector<ll> adj(mx, 0);
        rep(i, n)
        {
            adj[P[i]] = 2;
        }
        rep(i, m)
        {
            adj[Q[i]] = 1;
        }
        vector<ll> min1(m, INT_MAX);
        // sort(Q.begin(),Q.end());
        // sort(P.begin(),P.end());
        rep(i, m)
        {
            ll k = Q[i];
            ll j = Q[i];
            ll sumr = 0;
            ll suml = 0;
            int flagr = 1;
            int flagl = 1;
            while ((j >= 0 || k <= mx) && (flagl || flagr))
            {
                if (flagl)
                {
                    if (adj[j - 1] == 0)
                    {
                        suml++;
                    }
                    else if (adj[j - 1] == 1)
                    {
                        suml += 1 + s;
                    }
                    else if (adj[j - 1] == 2)
                    {
                        suml++;
                        flagl = 0;
                    }
                    j--;
                    if (flagl && j <= 0)
                    {
                        suml = INF;
                        flagl = 0;
                    }
                }
                if (flagr)
                {
                    if (adj[k + 1] == 0)
                    {
                        sumr++;
                    }
                    else if (adj[k + 1] == 1)
                    {
                        sumr += 1 + s;
                    }
                    else if (adj[k + 1] == 2)
                    {
                        sumr++;
                        flagr = 0;
                    }
                    k++;
                    if (flagr && k > mx)
                    {
                        sumr = INF;
                        flagr = 0;
                    }
                }
                if (!flagr && suml > sumr)
                {
                    break;
                }
                if (!flagl && sumr > suml)
                {
                    break;
                }
            }
            min1[i] = min(sumr, suml);
            min1[i] += 3;
        }
        cout << *max_element(min1.begin(), min1.end()) << endl;
        l++;
    }
}