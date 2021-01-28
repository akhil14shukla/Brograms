#include <algorithm> 
#include <chrono> 
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
    // freopen("output.txt", "w", stdout);
    for (int i = 1; i <= 20; i++)
    {
        clock_t start, end;
        double cpu_time_used;

        start = clock();
        /* Do the work. */
        fun(1,0,i);
        end = clock();
        cpu_time_used = (double)((double)(end - start)) / CLOCKS_PER_SEC;
        cout<<i<<" "<<(double)cpu_time_used<<endl;
    }
    return 0;
}