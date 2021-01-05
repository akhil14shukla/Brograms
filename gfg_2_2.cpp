#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)
#define rep(i,n) for(int i = 0;i<n;i++)

int main() {
	int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> a(n+2,vector<int>(n+2,1e9+7));
        vector<vector<bool>> b(n+2,vector<bool>(n+2,false));
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        int sx = 1, sy = 1, ex = n, ey = n;
        ll sum = a[1][1] + a[n][n];
        b[1][1] = b[n][n] = true;
        while(sx!=ex && sy!=ey){
            if(a[sx+1][sy]  ==  min(a[sx+1][sy],min(a[sx-1][sy],min(a[sx][sy+1],a[sx][sy-1]))) && !b[sx+1][sy]){
                sx++;
                sum+=a[sx][sy];
                b[sx][sy] = true;
            }
            else if(a[sx-1][sy]  ==  min(a[sx+1][sy],min(a[sx-1][sy],min(a[sx][sy+1],a[sx][sy-1]))) && !b[sx-1][sy]){
                sx--;
                sum+=a[sx][sy];
                b[sx][sy] = true;
            }
            else if(a[sx][sy+1]  ==  min(a[sx+1][sy],min(a[sx-1][sy],min(a[sx][sy+1],a[sx][sy-1]))) && !b[sx][sy+1]){
                sy++;
                sum+=a[sx][sy];
                b[sx][sy] = true;
            }
            else if(a[sx][sy-1]  ==  min(a[sx+1][sy],min(a[sx-1][sy],min(a[sx][sy+1],a[sx][sy-1]))) && !b[sx][sy-1]){
                sy--;
                sum+=a[sx][sy];
                b[sx][sy] = true;
            }

            if(a[ex+1][ey]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1]))) && !b[ex+1][ey]){
                ex++;
                sum+=a[ex][ey];
                b[ex][ey] = true;
            }
            else if(a[ex-1][ey]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1]))) && !b[ex-1][ey]){
                ex--;
                sum+=a[ex][ey];
                b[ex][ey] = true;
            }
            else if(a[ex][ey+1]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1]))) && !b[ex][ey+1]){
                ey++;
                sum+=a[ex][ey];
                b[ex][ey] = true;
            }
            else if(a[ex][ey-1]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1]))) && !b[ex][ey-1]){
                ey--;
                sum+=a[ex][ey];
                b[ex][ey] = true;
            }
        }
        cout<<sum - a[sx][sy]<<endl;
    }
	return 0;
}