#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)

vector<vector<vector<long long>>> cn(101, vector<vector<long long>>(101, vector<long long>(101, 0)));

long long cnt(int x, int y, int z) {
    if (cn[x][y][z]!=0) {
        return cn[x][y][z];
    }
    long long sum = 1;
    for (int i = 1;i<=x+y+z;i++) {
        sum = (sum*i)%mod;
    }
    for (int i = 1;i<=x;i++) {
        sum = (sum/i)%mod;
    }
    for (int i = 1;i<=y;i++) {
        sum = (sum/i)%mod;
    }

    for (int i = 1;i<=z;i++) {
        sum = (sum/i)%mod;
    }
    return cn[x][y][z] = cn[y][x][z] = cn[z][x][y] = cn[x][z][y] = cn[z][y][x]=cn[y][z][x] = sum;
}

long long rec(int x1, int y1, int z1, vector<vector<vector<long long>>> &dp) {
    for (int x = 0;x<=x1;x++)
        for (int y = 0;y<=y1;y++)
            for (int z = 0;z<=z1;z++) {
                if (dp[x][y][z]!=0) {
                    continue;
                }
                if(x>0){
                    dp[x][y][z] += ((10*dp[x-1][y][z])%mod+(4*cn[x-1][y][z])%mod)%mod;
                    cn[x][y][z] += cn[x-1][y][z];
                    cn[x][y][z] = cn[x][y][z]%mod;
                }
                if(y>0){
                    dp[x][y][z] += ((10*dp[x][y-1][z])%mod+(5*cn[x][y-1][z])%mod)%mod;
                    cn[x][y][z] += cn[x][y-1][z];
                    cn[x][y][z] = cn[x][y][z]%mod;
                }
                if(z>0){
                    dp[x][y][z] += ((10*dp[x][y][z-1])%mod+(6*cn[x][y][z-1])%mod)%mod;
                    cn[x][y][z] += cn[x][y][z-1];
                    cn[x][y][z] = cn[x][y][z]%mod;
                }
            }
    return dp[x1][y1][z1];
}

int main() {
    int t;
    cin>>t;
    vector<vector<vector<long long>>> dp(101, vector<vector<long long>>(101, vector<long long>(101, 0)));
    cn[0][0][0] = 1;
    while (t--) {
        int x, y, z;
        cin>>x>>y>>z;
        long long s = 0;
        rec(x, y, z, dp);
        for (int i = 0;i<=x;i++) {
            for (int j = 0;j<=y;j++) {
                for (int k = 0;k<=z;k++) {
                    s += dp[i][j][k];
                    s = s%mod;
                }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}