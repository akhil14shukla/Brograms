#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int rec(vector<int> &A, ll &count, int candies, set<vector<int>> &s)
{

    if (candies == 0)
    {
        s.insert(A);
        return 0;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] != 0)
        {
            A[i]--;
            rec(A, count, candies - 1, s);
            A[i]++;
        }
    }
    return 0;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 1));
    dp[0][0] = 0;
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0;
    // }
    // fo
    for (int i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= k; j++)
        {
            // for (int l = 0; l <= min(j, A[i - 1]); l++)
            // {
            //     dp[i][j] += dp[i - 1][j - l];
            // }
            // if (i != n && j != k)
            if (j - min(j, A[i - 1]) == 0)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j] - dp[i - 1][j - min(j, A[i - 1])];

            if (i != n)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
        // for(int j = 1;j<=k;j++){
        //     dp[i][j] += dp[i][j-1];
        // }
    }
    cout << dp[n][k];

    return 0;
}

//   0 1 2 3 4
//   1 1 0 0 0
//   2 1 2
//   3