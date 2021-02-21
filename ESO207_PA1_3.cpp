#include <iostream>
using namespace std;
#define ll long long int
// #define mod int(1e9 + 7)
ll *multiply(ll *a1, ll *a2)
{
    ll x1 = (a1[0] * a2[0] + a1[1] * a2[2]) % (1000000007);
    ll x2 = (a1[0] * a2[1] + a1[1] * a2[3]) % (1000000007);
    a1[0] = x1;
    a1[1] = x2;
    a1[2] = x2;
    a1[3] = x1;
    return a1;
}

ll *rec(ll *a, ll n)
{
    if (n > 1)
    {
        if (n % 2 == 1)
        {
            ll t[4] = {3, 1, 1, 3};
            rec(a, n / 2);
            return a = multiply(multiply(a, a), t);
        }
        else
        {
            rec(a, n / 2);
            return a = multiply(a, a);
        }
    }
    return a;
}


int main()
{
    ll n;
    cin >> n;
    ll a[4] = {3, 1, 1, 3};
    ll *f = rec(a, n);
    cout << f[0] % (1000000007) << ", " << f[1] % (1000000007);
    return 0;
}
