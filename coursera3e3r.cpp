#include <iostream>
#include <vector>
#include <algorithm>

long long max(long long a, long long b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
long long MaxPairwiseProduct(const std::vector<long long> &numbers)
{
    long long max_product = 0;
    long long n = numbers.size();
    long long ma2 = 0, ma1 = 0;
    for (int first = 0; first < n; ++first)
    {
        ma2 = max(ma2, numbers[first]);
    }
    for (int first = 0; first < n; ++first)
    {
        if (numbers[first] != ma2)
            ma1 = max(ma1, numbers[first]);
    }
    max_product = ma2 * ma1;
    return max_product;
}

int main()
{
    long long n;
    std::cin >> n;
    std::vector<long long> numbers(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> numbers[i];
    }
sort(numbers.begin(),numbers.end());
    std::cout << numbers[numbers.size()-1]*numbers[numbers.size()-2]
              << "\n";
    return 0;
}