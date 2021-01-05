#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B, int C) {
        int n = A.size();
    vector<vector<int>> dp(n+1, vector<int>(C+1, 0));
    
    // Base Cases
    // for(int j = 0 ; j <= C ; j++){
    //     dp[n-1][j] = (B[n-1]<=j ? A[n-1] : 0);
    // }
    dp[0][B[0]] = A[0];
    // Filling the dp table
    // for(int i = n-1 ; i >= 0 ; i--){
    //     for(int j = 0 ; j <= C ; j++){
    //         if(j-B[i]>=0)
    //         dp[i][j] = max(A[i]+dp[i+1][j-B[i]], dp[i+1][j]);
    //     }
    // }
    for(int i = 1;i<n ;i++){
        for(int j = 0;j<=C;j++){
            if(j-B[i]>=0)
            dp[i][j] = max(A[i] + dp[i-1][j-B[i]], dp[i-1][j]);
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int max1 = 0;
    for(int i = 0;i<=C;i++){
        max1 = max(max1,dp[n-1][i]);
    }
    return max1;
}

int main(){
    vector<int> A = {504, 449, 201, 459, 619, 581, 797, 799, 282, 590, 799, 10, 158, 473, 623};
    vector<int> B = {39, 93, 39, 80, 91, 58, 59, 92, 16, 89, 57, 12, 3, 35, 73 };
    cout<<solve(A,B,56);
}