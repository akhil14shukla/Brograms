#include <iostream>
using namespace std;
#define ll long long int

ll fun(ll x, ll y, ll n)
{
    if (n == 0)
    {
        return x;
    }
    return fun((3 * x + y) % (1000000007), (3 * y + x) % (1000000007), n - 1);
}
int main()
{
    // int n = 0;;
    // cin>>n;
    for (ll n = 0; n <= 1000; n++)
    {
        long long int a[2] = {1, 0};
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int temp = a[0];
            a[0] = (3 * a[0] + a[1]) % mod;
            a[1] = (3 * a[1] + temp) % mod;
        }
        cout << a[0] << endl;
    }
    return 0;
}