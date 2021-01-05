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
        ll m1 = *max_element(L.begin(), L.end());
        ll m2 = *max_element(W.begin(), W.end());
        vector<ll> vis(m1 + m2 + 2, 0);
        vector<pair<pair<ll, ll>,vector<pair<pair<ll,ll>,ll>>>> st;
        vector<ll> dp(n, 0);
        dp[0] = 2 * (W[0] + H[0]);
        st.push_back({{L[0], L[0] + W[0]},{{{L[0],L[0] + W[0]},H[0]}}});
        // sort(st.begin(), st.end());

        rep2(i, 1, n - 1)
        {
            dp[i] = dp[i - 1] + 2 * W[i] + 2 * H[i];
            int k = 0;
            int flag = 0;
            ll maxhr = 0, maxhl = 0;
            int k1 = 0, k2 = 0;
            int flagr = 0, flagl = 0;
            vector<pair<pair<ll, ll>,vector<pair<pair<ll,ll>,ll>>>> st2;
            while (k < st.size())
            {
                // dp[i] = dp[i - 1] + 2 * W[i];
                if (L[i] <= st[k].first.second && L[i] >= st[k].first.first && L[i] + W[i] > st[k].first.second)
                {
                    dp[i] = dp[i] - 2 * (st[k].first.second - L[i]);
                    maxhr = max(maxhr, st[k].second);
                    k1 = k+1;
                    flagl = 1;
                    flag = 1;
                }
                else if (L[i] + W[i] <= st[k].first.second && L[i] + W[i] >= st[k].first.first && L[i] < st[k].first.first)
                {
                    dp[i] = dp[i] - 2 * (L[i] + W[i] - st[k].first.first);
                    maxhl = max(maxhl, st[k].second);
                    k2 = k+1;
                    flagr = 1;
                    flag = 1;
                }
                else if (L[i] <= st[k].first.first && L[i] + W[i] >= st[k].first.second)
                {
                    dp[i] = dp[i] - 2 * (st[k].first.second - st[k].first.first);
                    maxhl = max(maxhl, st[k].second);
                    maxhr = max(maxhr, st[k].second);
                    st2.push_back({{L[i], L[i] + W[i]}, H[i]});
                    dp[i] = dp[i] - 2*st[k].second;
                    flag = 1;
                }
                else if (L[i] > st[k].first.first && L[i] + W[i] < st[k].first.second)
                {
                    dp[i] = dp[i - 1];
                    maxhl = max(maxhl, st[k].second);
                    maxhr = max(maxhr, st[k].second);
                    st2.push_back({{st[k].first.first, L[i]}, st[k].second});
                    st2.push_back({{L[i] + W[i], st[k].first.second}, st[k].second});
                    st2.push_back({{L[i], L[i] + W[i]}, H[i]});
                    flag = 1;
                }
                else
                {
                    st2.push_back(st[k]);
                }
                k++;
            }

            // dp[i] = dp[i] + H[i] - maxhl + H[i] - maxhr;
            if (k1 && k2)
            {
                st2.push_back({{st[k1-1].first.first, st[k2-1].first.second}, H[i]});
                dp[i]  = dp[i] - 2*st[k1-1].second - 2*st[k2-1].second;
            }
            else if (k1)
            {
                st2.push_back({{st[k1-1].first.first, L[i] + W[i]}, H[i]});
                dp[i] = dp[i] - 2*st[k1-1].second;
            }
            else if (k2)
            {
                st2.push_back({{L[i], st[k2-1].first.second}, H[i]});
                dp[i] = dp[i] - 2*st[k2-1].second;
            }
            // dp[i] = dp[i]-max
            st = st2;
            if (!flag)
                st.push_back({{L[i], L[i] + W[i]}, H[i]});
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