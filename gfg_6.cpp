#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int i, int j){
    if(i>=s1.size() || j>=s2.size()){
        return 0;
    }
    if(s1[i] == s2[j]){
        return 1 + lcs(s1,s2,i+1,j+1);
    }
    else{
        return max(lcs(s1,s2,i+1,j),lcs(s1,s2,i,j+1));
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n, m;
        cin>>n>>m;
	    string s1, s2;
	    cin>>s1>>s2;
	    long long count = 0;
	    count = abs(n-m);
	    int i = 0, j = 0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int  start = 0;
	    for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        int l = 0;
	    cout<<max(m,n) - dp[n][m]<<endl;
	}
	return 0;
}