#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        vector<vector<ll>> dp(n, vector<ll>(n, 1));
        ll count = 0;
        for (int i = 0;i<n;i++) {
            cin>>dp[n-1][i];
            if (dp[n-1][i]<k)
                count++;
        }

        for (int i = n-2;i>=0;i--) {
            for (int j = 0;j<n;j++) {
                if (j+n-i-1<n) {
                    dp[i][j] = dp[i+1][j]*dp[n-1][j+n-i-1];
                    if (dp[i][j]<k && dp[i][j]>0)
                        count++;
                    else if(dp[i][j]<0){
                        dp[i][j] = -1;
                    }
                }
            }
        }
        int start = 0, end = 0;
        ll pd = 1;
        while(start<=end && end<n){
            pd *= a[end];
        }
        cout<<count<<endl;
    }
    return 0;
}