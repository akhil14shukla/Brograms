#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m)
{
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current = 1;
    long long dp;
    for (long long i = 0; i < m * m; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if (previous == 0 and current == 1)
        {
            dp = i + 1;
            break;
        }
    }
    previous = 0;
    current = 1;
    n = n % dp;
    for (long long i = 0; i < n - 1; ++i)
    {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        // dp[i] = current;
    }
    if (n == 0)
        return 0;
    if (n == 1) : return 1 return current % m;
}

int main()
{
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}