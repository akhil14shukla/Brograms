#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}
vector<int> dp(2 * 10e5 + 1, -1);

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int eit = ceil(double(n) / double(4));
        int nin = n - eit;
        long final = 0;
        for (int i = 0; i < nin; i++)
        {
            cout<<9;
        }
        for (int i = 0; i < eit; i++)
        {
            cout<<8;
        }
        cout<<endl;
    }
    return 0;
}