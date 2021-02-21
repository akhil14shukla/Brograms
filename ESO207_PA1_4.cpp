#include <algorithm>
#include <chrono>
#include <iostream>
using namespace std;
#define ll long long int
#define mod int(1e9 + 7)

ll a[2] = {3, 1};
ll D(ll n);
ll U(ll n)
{
    if (n == 0)
    {
        return 1;
    }
    return (3 * U(n - 1) + D(n - 1)) % mod;
}
ll D(ll n)
{
    if (n == 0)
    {
        return 0;
    }
    return (3 * D(n - 1) + U(n - 1)) % mod;
}
ll rec1(ll &x, ll &y, ll n)
{
    if (n == 0)
    {
        return x;
    }
    ll temp = x;
    x = (3 * x + y) % (1000000007);
    y = (3 * y + temp) % (1000000007);
    return rec1(x, y, n - 1);
}

ll *multiply(ll a2[])
{
    ll x1 = ((a[0] * a2[0]) % (ll)(1e9 + 7) + (a[1] * a2[1]) % (ll)(1e9 + 7)) % (ll)(1e9 + 7);
    ll x2 = ((a[0] * a2[1]) % (ll)(1e9 + 7) + (a[1] * a2[0]) % (ll)(1e9 + 7)) % (ll)(1e9 + 7);
    a[0] = x1;
    a[1] = x2;
    // a2 = a1;
    return a;
}

ll *rec(ll n)
{
    if (n > 1)
    {
        if (n % 2 == 1)
        {
            ll t[2] = {3, 1};
            rec(n / 2);
            multiply(a);
            return multiply(t);
        }
        else
        {
            rec(n / 2);
            return multiply(a);
        }
    }
    return a;
}

void iter(ll n)
{
    long long int a[2] = {1, 0};
    // int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
        int temp = a[0];
        a[0] = (3 * a[0] + a[1]) % mod;
        a[1] = (3 * a[1] + temp) % mod;
    }
}

int main()
{
    freopen("ESO207_PA1_Rec.txt", "w", stdout);
    cout << "num,time" << endl;
    for (ll i = 1; i <= 20; i++)
    {
        double sum = 0;

        for (int j = 1; j <= 1000; j++)
        {
            ll x = 1, y = 0;

            clock_t star;
            double cpu_time_used;
            star = clock();
            U(i);
            D(i);
            star = clock() - star;
            cpu_time_used = 1e6 * ((double)(star)) / CLOCKS_PER_SEC;
            sum += cpu_time_used;
        }
        // cout << a[0] << " " << a[1] << endl;
        sum = sum / 1000;
        cout << i << "," << sum << endl;
    }
    return 0;
}