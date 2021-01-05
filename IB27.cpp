#include <bits/stdc++.h>
using namespace std;

int longestSubsequenceLength(const vector<int> &A)
{
    vector<int> dp(A.size(), 1);
    // int last = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        for(int j = 0;j<i;j++){
            if(A[i]>=A[j]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }

    vector<int> dp2(A.size(), 1);
    for (int i = A.size()-1; i>=0; i--)
    {
        for(int j = A.size()-1;j>i;j--){
            if(A[i]>=A[j]){
                dp2[i] = max(dp2[i],dp2[j]+1);
            }
        }
    }
    int final = 0;
    for (int i = 0; i < A.size(); i++)
    {
        final = max(final, dp[i] + dp2[i]-1);
    }
    return final;
}

int main()
{
    vector<int> A = {7, 6, 8, 10, 2, 5, 12, 30, 31, 20, 22, 18};
    cout << longestSubsequenceLength(A);
}