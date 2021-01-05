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
        int n1;
        cin >> n1;
        vector<int> f;
        f.push_back(6);
        f.push_back(10);
        f.push_back(14);
        f.push_back(n1-30);
        if(n1 == 36 || n1 == 40 || n1 == 44){
            f[2] = 15;
            f[3] = n1 - 31;
        }
        if (n1>30)
        {
            cout << "YES" << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << f[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}