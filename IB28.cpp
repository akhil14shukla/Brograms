#include <bits/stdc++.h>
using namespace std;

int rec(string A)
{
    string rev = A;
    reverse(rev.begin(), rev.end());
    return rev == A;
}

int minCut(string A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = i; j < A.size(); j++)
        {
            if (rec(A.substr(i, j - i + 1)))
            {
                for (int x = 0; x < i; x++)
                {
                    dp[i][j] = max(dp[i][j], dp[x][i - 1] + 1);
                }
                if (i == 0)
                {
                    dp[i][j] = 1;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[A.size() - 1][A.size() - 1] - 1 < 0 ? 0 : dp[A.size() - 1][A.size() - 1] - 1;
}

int main()
{
    // vector<string> A = {};
    cout << minCut("aab");
}