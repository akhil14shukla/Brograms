#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)
#define rep(i,n) for(int i = 0;i<n;i++)

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        vector<vector<int>> a(n+2, vector<int>(n+2, 1e9+7));
        for (int i = 1;i<=n;i++) {
            for (int j = 1;j<=n;j++) {
                cin>>a[i][j];
            }
        }
        if (n == 0) {
            cout<<0<<endl;
            continue;
        }
        if (n==1) {
            cout<<a[1][1]<<endl;
            continue;
        }
        int sx = 1, sy = 1, ex = n, ey = n;
        ll sum = a[1][1] + a[n][n];
        a[n][n] = a[1][1] = 1e9+7;
        while (abs(sx-ex) + abs(sy - ey) != 1) {
            if (a[sx+1][sy]  ==  min(a[sx+1][sy], min(a[sx-1][sy], min(a[sx][sy+1], a[sx][sy-1])))) {
                sx++;
                sum+=a[sx][sy];
                a[sx][sy] = 1e9+7;
            }
            else if (a[sx-1][sy]  ==  min(a[sx+1][sy], min(a[sx-1][sy], min(a[sx][sy+1], a[sx][sy-1])))) {
                sx--;
                sum+=a[sx][sy];
                a[sx][sy] = 1e9+7;
            }
            else if (a[sx][sy+1]  ==  min(a[sx+1][sy], min(a[sx-1][sy], min(a[sx][sy+1], a[sx][sy-1])))) {
                sy++;
                sum+=a[sx][sy];
                a[sx][sy] = 1e9+7;
            }
            else if (a[sx][sy-1]  ==  min(a[sx+1][sy], min(a[sx-1][sy], min(a[sx][sy+1], a[sx][sy-1])))) {
                sy--;
                sum+=a[sx][sy];
                a[sx][sy] = 1e9+7;
            }

            if ((abs(sx-ex) + abs(sy - ey)) == 1) {
                break;
            }


            // if(a[ex-1][ey]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1])))){
            //     ex--;
            //     sum+=a[ex][ey];
            //     a[ex][ey] = 1e9+7;
            // }
            // else if(a[ex][ey-1]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1])))){
            //     ey--;
            //     sum+=a[ex][ey];
            //     a[ex][ey] = 1e9+7;
            // }
            // else if(a[ex+1][ey]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1])))){
            //     ex++;
            //     sum+=a[ex][ey];
            //     a[ex][ey] = 1e9+7;
            // }
            // else if(a[ex][ey+1]  ==  min(a[ex+1][ey],min(a[ex-1][ey],min(a[ex][ey+1],a[ex][ey-1])))){
            //     ey++;
            //     sum+=a[ex][ey];
            //     a[ex][ey] = 1e9+7;
            // }

        }
        cout<<sum<<endl;
    }
    return 0;
}