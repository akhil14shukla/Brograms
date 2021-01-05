#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

int count_set_bit(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
        {
            count++;
        }
        n = n >> 1; //right shift 1 bit
    }
    return count;
}

int solver(vector<int> &dp, const vector<int> &b, const vector<int> &c, int cost, int i)
{
    if (cost == 0)
        return dp[cost] = 0;
    if (i == b.size() || i<0)
        return 100000;
    if (dp[cost] != -1)
        return dp[cost];
    if (b[i] <= cost)
        return dp[cost] = min(solver(dp, b, c, cost - b[i], i) + c[i], min(solver(dp, b, c, cost, i + 1),solver(dp,b,c,cost,i-1)));
    return dp[cost] = min(solver(dp, b, c, cost, i + 1),solver(dp,b,c,cost,i-1));
}
int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int ans = 0;
    int maxi = *max_element(A.begin(), A.end());
    //cout<<maxi<<endl<<"******"<<endl;
    vector<int> dp(maxi + 1, -1);
    solver(dp, B, C, maxi, 0);
    for (int i = 0; i < A.size(); i++)
    {
        ans += dp[A[i]];
        // cout<<dp[i]<<endl;
    }
    //cout<<"*********"<<endl;
    return ans;
}

int main()
{
    vector<int> A = {2, 3, 1, 5, 4};
    vector<int> B = {3, 2, 4, 1};
    vector<int> C = {1, 2, 5, 10};
    cout << solve(A, B, C);
    return 0;
}