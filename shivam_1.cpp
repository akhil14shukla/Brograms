#include <time.h>
#include <cstdio>
#include <iostream>
#define ll long long int
#define MOD 1000000007
using namespace std;


int main()
{
    ll n;
    cin>>n;
    ll ans = 0;
    ll temp = 0;
    ll a=1,b=0;
    for(ll i=1;i<=n;i++){
      ans = (3*a + b)%MOD;
      temp = (a + 3*b)%MOD;
      a = ans;
      b = temp;
    }
    cout<<(ans%MOD);
    return 0;
}