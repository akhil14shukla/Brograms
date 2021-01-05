#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string a[2];
        cin >> a[0] >> a[1];
        int flag = 0;
        vector<vector<pair<bool, bool>>> dp(2, vector<pair<bool, bool>>(n + 1, {false, false}));
        dp[0][0] = dp[0][1] = {1, 1};
        for (int i = 0; i < n;i++)
        {
            if ((a[flag][i] == '1' || a[flag][i] == '2') && dp[flag][i].first == 1 && dp[flag][i].second == 1)
            {
                dp[flag][i + 1] = {1, 1};
            }
            // if ((a[!flag][i] == '1' || a[!flag][i] == '2') && dp[!flag][i].first == 1 && dp[!flag][i].second == 1)
            // {
            //     dp[!flag][i + 1] = {1, 1};
            // }
            if (a[flag][i] - '3' >= 0 && dp[flag][i].first == 1 && dp[flag][i].second == 1)
            {
                dp[!flag][i] = {1, 0};
                // i--;
                flag = !flag;
            }
            // if(a[flag][i] -'3' >=0 && flag == 0 && dp[!flag][i].first == 1 && dp[!flag][i].second == 1){{
            //     dp[!flag][i] = {1,0};
            // }
            if (a[flag][i] - '3' >= 0 && dp[flag][i].first == 1 && dp[flag][i].second == 0)
            {
                dp[flag][i + 1] = {1, 1};
            }
        }
        if (dp[1][n].first == 1 && dp[1][n].second == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}