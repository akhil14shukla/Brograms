#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
using namespace std;
int min(int a, int b){
    if(a>b)return b;
    return a;
}
int max(int a, int b){
    if(a>b)return a;
    return b;
}
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n,k,p;
        cin>>n>>k>>p;
        int a[n][k];
        int sum[n][k],dp[n+1][p+1];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                cin>>a[i][j];
                if(j==0)sum[i][j]=a[i][j];
                else sum[i][j] = sum[i][j-1]+a[i][j];
                //cout<<sum[i][j]<<" ";
            }
            //cout<<endl;
        }
        for(int i=0;i=<n;i++)
        {
            for(int j=0;j<=p;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=p;j++)
            {
                if(i==1){
                    if(j<k)dp[i][j] = sum[i-1][j];
                    else dp[i][j] = 0;
                    continue;
                }
                dp[i][j]=max(a[i][j], dp[i-1][j]);
                for(int x=1; x<=min(j,k);x++)
                {
                    dp[i][j] = max(dp[i][j],sum[i-1][x-1]+dp[i-1][j-x]);
                }
            }
        }
        cout<<"Case #"<<t<<": "<<dp[n-1][p-1]<<endl;
    }
}