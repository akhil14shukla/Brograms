#include <chrono>
#include <iostream>
using namespace std;
#define ll long long int

int main()
{
    int n,k;
    cin>>n;
    int a[n+1];
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    a[0] = 0;
    cin>>k;
    for(int i = 1;i<=n;i++){
        a[i] += a[i-1];
    }
    sort()
    return 0;
}