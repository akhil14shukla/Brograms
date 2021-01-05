#include <bits/stdc++.h>
using namespace std;

int solve(string A)
{
    string rev = A;
    reverse(rev.begin(), rev.end());
    vector<vector<int>> dp(A.size() + 1, vector<int>(A.size() + 1, 0));
    int max1 = 0;
    for (int i = 1; i <= A.size(); i++)
    {
        for (int j = 1; j <= A.size(); j++)
        {
            if (A[i - 1] == rev[j - 1])
            {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1]));
            }
            max1 = max(max1, dp[i][j]);
        }
    }
    return max1;
}

int main()
{
    string A = "bebeeed";
    cout << solve(A);
}