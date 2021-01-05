#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (i == 0)
            {
                dp[i][j] = A[j];
                continue;
            }
            if (A[i + j] - dp[i - 1][j] >= A[j] - dp[i - 1][j + 1])
            {
                dp[i][j] = A[i + j] - dp[i - 1][j];
            }
            else
            {
                dp[i][j] = A[j] - dp[i - 1][j + 1];
            }
        }
    }
    cout << dp[n - 1][0] << endl;
}