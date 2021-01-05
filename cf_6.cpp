#include <iostream>
#include <iomanip>
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

//extra
void fastscan(int &number) //much faster way of input, only integers
{
    //variable to indicate sign of input number     //getchar_unlocked() fastest way of input  and lly, putchar_unlocked(c)
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
//over

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

// int rec(vector < in)

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
    {
        ll p, f;
        cin >> p >> f;
        ll cnts, cntw;
        cin >> cnts >> cntw;
        ll s, w;
        cin >> s >> w;
        vector<int> dp(f + 1, 0);
        vector<pair<int, int>> store(f+ 1, {0, 0});
        cnts = 3;
        cntw = 3;
        for (int i = min(s, w); i <= f; i++)
        {
            // int t=i;
            // while(t--){
            int t = max(i - s, i - w);
            // dp[i] = max(dp[i - s] + 1, dp[i - w] + 1);
            if (dp[i - s] + 1 > dp[i - w] + 1 && cnts - store[i - s].first > 0)
            {
                dp[i] = dp[i - s] + 1;
                store[i].second = store[i - s].second;
                store[i].first = store[i - s].first + 1;
            }
            else if (dp[i - s] + 1 < dp[i - w] + 1 && cntw - store[i - w].second > 0)
            {
                dp[i] = dp[i - w] + 1;
                store[i].second = store[i - w].second + 1;
                store[i].first = store[i - w].first;
            }
            else if (dp[i - s] == dp[i - w] && (cnts - store[t].first > 0 || cntw - store[t].second > 0))
            {
                dp[i] = dp[t] + 1;
                if (t == i - s && cnts - store[t].first > 0)
                {
                    store[i].first = store[t].first + 1;
                    store[i].second = store[t].second;
                }
                else if (t == i - w && cntw - store[t].second > 0)
                {
                    store[i].first = store[t].first;
                    store[i].second = store[t].second + 1;
                }
            }
            else
            {
                dp[i] = dp[i - 1];
                store[i] = store[i - 1];
            }
            // }
        }
        cnts = cnts - store[p].first;
        cntw = cntw - store[p].second;
        vector<int> dp2(f + 1, 0);
        vector<pair<ll, ll>> store2(f + 1, {0, 0});
        for (int i = min(s, w); i <= f; i++)
        {
            if (dp2[i - s] + 1 > dp2[i - w] + 1 && cnts - store2[i - s].first > 0)
            {
                dp2[i] = dp2[i - s] + 1;
                store2[i].second = store2[i - s].second;
                store2[i].first = store2[i - s].first + 1;
            }
            else if (dp2[i - s] + 1 <= dp2[i - w] + 1 && cntw - store2[i - w].second > 0)
            {
                dp2[i] = dp2[i - w] + 1;
                store2[i].second = store2[i - w].second + 1;
                store2[i].first = store2[i - w].first;
            }
            else
            {
                dp2[i] = dp2[i - 1];
                store2[i] = store2[i - 1];
            }
            // }
        }
        cout << dp[p] + dp2[f] << endl;
    }

    return 0;
}
