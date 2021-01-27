#include <iostream>
using namespace std;
#define ll long long int

ll *multiply(ll a1[4], ll a2[4])
{
    ll x1 = a1[0] * a2[0] + a1[1] * a2[2];
    ll x2 = a1[0] * a2[1] + a1[1] * a2[3];
    ll x[4] = {x1, x2, x2, x1};
    return x;
}

ll *rec(ll a[4], ll n)
{
    if (n % 2 == 1)
    {
        ll t[4] = {3,1,1,3};
        return multiply(multiply(rec(a, n / 2) , rec(a, n / 2)),t);
    }
}

int main()
{
    ll n;
    cin >> n;
    ll a[4] = {3, 1, 1, 3};
    ll *f = rec(a,n);
    cout<<f[0]<<" "<<f[1];
    return 0;
}
