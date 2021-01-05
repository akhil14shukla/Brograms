#include <bits/stdc++.h>
using namespace std;

int check(string S, string revS)
{
    if (S.size() > revS.size())
    {
        swap(S, revS);
    }
    vector<vector<int>> dp(S.size() + 1, vector<int>(revS.size() + 1, 0));
    for (int i = 0; i <= S.size(); i++)
    {
        for (int j = 0; j <= revS.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (S[i - 1] == revS[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[S.size()][revS.size()];
}
vector<int> maxLCS(string A)
{
    // string S, revS;
    int mx = 0;
    int j = 0;
    string S = A;
    string revS = A;
    reverse(revS.begin(), revS.end());
    vector<vector<int>> dp(S.size() + 1, vector<int>(revS.size() + 1, 0));
    for (int i = 0; i <= S.size(); i++)
    {
        for (int j = 0; j <= revS.size(); j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (S[i - 1] == revS[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    for(int i = 1;i<A.size()-1;i++){
        if(dp[i][A.size()-i]>mx){
            mx = dp[i][A.size()-i];
            j = i;
        }
    }
    vector<int> f(2);
    f[0] = j;
    f[1] = mx;
    return f;
}



int cntMatrix(vector<int> &A) {
    int n = A.size();
    if(n == 1){
        return 1;
    }
    vector<int> dp(A.size(),1);
    for(int i = 1;i<A.size();i++){
        if(A[i]>A[i-1]){
            dp[i] = dp[i-1] + 1;
        }
    }
    int mn = dp[A.size()-1];
    for(int i = A.size()-1;i>=0;){
        if(dp[i]<mn){
            mn = dp[i];
        }
        i = i - dp[i];
    }
    vector<int> fac;
    for(int i = 1;i<=mn;i++){
        if(n%i == 0){
            fac.push_back(i);
        }
    }
    // vector<int> dp((n/2)+1, -1);
    vector<int> fct(mn+1,1);
    for(int i = 1;i<=mn+1;i++){
        fct[i] = i*fct[i-1];
    }
    long long total = 0;
    for(int i = 0;i<fac.size();i++){
        // total = (total + ((long long)(pow(fct[fac[i]],n/fac[i]))%100000007))%100000007;
        long long temp = 1;
        for(int j = fac[i];j>=1;j--){
            temp = (temp * j)%1000000007;
        }
        long long f1 =1;
        for(int j = 1;j<=(n/fac[i]);j++){
            f1 = (f1*temp)%1000000007;
        }
        total = (total + f1)%1000000007;
    }
    return total;
}

int main()
{
    string A = "abba";
    vector<int> f = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 46, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 25, 47, 48, 49, 50 };
    cout<<cntMatrix(f);
    return 0;
}