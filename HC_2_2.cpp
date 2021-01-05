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
    cin.open("chap2f.txt");
    ofstream Out("output.txt");
    cin >> f;
    int l = 1;
    while (l <= f)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> L(n);
        rep(i, k)
        {
            cin >> L[i];
        }
        ll Al, Bl, Cl, Dl;
        cin >> Al >> Bl >> Cl >> Dl;
        vector<ll> W(n);
        rep(i, k)
        {
            cin >> W[i];
        }
        ll Aw, Bw, Cw, Dw;
        cin >> Aw >> Bw >> Cw >> Dw;
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
            W[i] = (Aw * W[i - 2] + Bw * W[i - 1] + Cw) % Dw + 1;
        }
        ll m1 = *max_element(L.begin(),L.end());
        ll m2 = *max_element(W.begin(),W.end());
        vector<ll> vis(m1 + m2 + 2, 0);
        vector<ll> dp(n, 0);
        dp[0] = 2 * (W[0] + H[0]);
        int temp = 0;
        while (temp < W[0])
        {
            vis[L[0] + temp] = H[0]; //vis[i] represents if there is a rectanlge or any part of it betweem i+1 and i
            temp++;
        }

        rep2(i, 1, n - 1)
        {
            ll start = L[i];
            ll k = start;
            ll end = L[i] + W[i];
            dp[i] = dp[i - 1];
            while (k < end)
            {
                if (vis[k] == 0)
                {
                    dp[i] += 2;
                    vis[k] = H[i];
                    if (vis[k - 1] == 0)
                    {
                        dp[i] += H[i];
                    }
                    else
                    {
                        dp[i] -= H[i];
                    }
                    if (vis[k + 1] == 0)
                    {
                        dp[i] += H[i];
                    }
                    else
                    {
                        dp[i] -= H[i];
                    }
                }
                k++;
            }
            // if (vis[end] == 0)
            // {
            //     dp[i] += H[i];
            // }
            // if(vis[end]!=0)
            // {
            //     dp[i] -= H[i];
            // }
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