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
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> r1(r), g1(g), b1(b);
    rep(i, r)
    {
        cin >> r1[i];
    }
    rep(i, g)
    {
        cin >> g1[i];
    }
    rep(i, b)
    {
        cin >> b1[i];
    }
    ll sum = 0;
    int max1 = max(r1.size(), max(b1.size(), g1.size()));
    rep(i, max1 - r1.size() + 4)
        r1.pb(0);
    rep(i, max1 - b1.size() + 4)
        b1.pb(0);
    rep(i, max1 - r1.size() + 4)
        g1.pb(0);

    sort(r1.begin(), r1.end());
    sort(b1.begin(), b1.end());
    sort(g1.begin(), g1.end());
    while ((r1.size() != 0 && b1.size() != 0) || (r1.size() != 0 && g1.size() != 0) || (b1.size() != 0 && g1.size() != 0))
    {
        if((r1.back() == 0 && g1.back() == 0) || (r1.back() == 0 && b1.back() == 0) || (b1.back() == 0 && g1.back() == 0)){
            break;
        }
        ll m1 = max(r1.back(), max(g1.back(), b1.back()));
        if (m1 == r1.back())
        {
            r1.pop_back();
            ll m2 = max(g1.back(), b1.back());
            sum += m1 * m2;
            if (m2 == g1.back())
            {
                g1.pop_back();
            }
            else
            {
                b1.pop_back();
            }
        }
        else if (m1 == g1.back())
        {
            g1.pop_back();
            ll m2 = max(r1.back(), b1.back());
            sum += m1 * m2;
            if (m2 == r1.back())
            {
                r1.pop_back();
            }
            else
            {
                b1.pop_back();
            }
        }
        else if (m1 == b1.back())
        {
            b1.pop_back();
            ll m2 = max(g1.back(), r1.back());
            sum += m1 * m2;
            if (m2 == g1.back())
            {
                g1.pop_back();
            }
            else
            {
                r1.pop_back();
            }
        }
    }
    cout << sum << endl;
    return 0;
}
