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
        ll n, k, w;
        cin >> n >> k >> w;
        vector<ll> L(n);
        rep(i, k)
        {
            cin >> L[i];
        }
        ll Al, Bl, Cl, Dl;
        cin >> Al >> Bl >> Cl >> Dl;
        vector<ll> H(n);
        rep(i, k)
        {
            cin >> H[i];
        }
        ll Ah, Bh, Ch, Dh;
        cin >> Ah >> Bh >> Ch >> Dh;
        rep2(i, k, n - 1)
        {
            L[i] = (Al * L[i - 2] + Bl * L[i - 1] + Cl) % Dl + 1;
            H[i] = (Ah * H[i - 2] + Bh * H[i - 1] + Ch) % Dh + 1;
        }
        vector<ll> vis(L[n - 1] + w + 2, 0);
        vector<ll> dp(n, 0);
        dp[0] = 2 * (w + H[0]);
        int temp = 0;
        while (temp <= w)
        {
            vis[L[0] + temp] = H[0];
            temp++;
        }
        rep2(i, 1, n - 1)
        {
            // int k = 0;
            // while (k < w)
            // {
            //     if (vis[L[i] + k + 1] == 0)
            //     {
            //         vis[L[i] + k] = max(vis[L[i] + k], H[i]) - min(vis[L[i] + k], H[i]);
            //     }
            //     else{

            //     }
            // }
            if (L[i - 1] + w < L[i])
            {
                dp[i] = dp[i - 1] + 2 * (w + H[i]);
                int k = 0;
                while (k <= w)
                {
                    vis[L[i] + k] = max(vis[L[i] + k], H[i]);
                    k++;
                }
            }
            else
            {
                ll sleight = vis[L[i]];
                dp[i] = dp[i - 1];
                if (L[i] - L[i - 1] > 0)
                {
                    dp[i] += 2 * (L[i] - L[i - 1]);
                }
                if (H[i] > sleight)
                {
                    dp[i] = dp[i] + 2 * (H[i] - sleight);
                }
                else if (H[i] <= sleight)
                {
                    dp[i] = dp[i];
                }

                int k = 0;
                while (k <= w)
                {
                    vis[L[i] + k] = max(vis[L[i] + k], H[i]);
                    k++;
                }
            }
            dp[i] = dp[i] % 1000000007;
        }
        ll final = 1;
        rep(i, n)
        {
            final *= dp[i];
            final = final % 1000000007;
        }
        Out << "Case #" << l << ":"
            << " " << final << el;
        l++;
    }
}