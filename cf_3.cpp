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
        string s;
        cin >> s;
        ll sum = 0;
        ll count = 0;
        // int last = n-1;
        // for (int i = 0; i < n; i++)
        // {
        //     if (s[i] == '0')
        //     {
        //         count++;
        //     }
        // }
        ll final = 0;

        unordered_map<ll,ll> s1;
        vector<int> dp(n + 1, 0);
        s1[0]++;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1] + s[i - 1] - '0';
            // s1[dp[i] - i]++;
            if (s1.find(dp[i] - i) != s1.end())
            {
                
                final+=s1[dp[i]-i];
                s1[dp[i]-i]++;
            }
            else
            {
                s1[dp[i] - i]++;
                // final+=s1[dp[i]-i];
            }
        }
        // for(auto i = s1.begin();i!=s1.end();i++){
        //     final+=2*i->second-2;
        // }
        cout << final << endl;
    }

    return 0;
}
