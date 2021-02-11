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
        // clock_t star;
        // double cpu_time_used;

        // star = clock();
        // /* Do the work. */
        // fun(1,0,i);
        // star = clock() - star;
        // cpu_time_used = (double)((double)(star)) / CLOCKS_PER_SEC;
        // cout<<i<<" "<<(double)cpu_time_used<<endl;
        auto t1 = std::chrono::high_resolution_clock::now();
        fun(1,0,i);
        auto t2 = std::chrono::high_resolution_clock::now();

        double duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();

        std::cout << duration<<endl;
    }
    return 0;
}