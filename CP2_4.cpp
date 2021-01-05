#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
#define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll.i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpair vector<pair<int, int>>
#define mp make_pair
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fir first
#define sec second
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
#define fs fastscan

#define vrep(vec) for (const auto &value : vec)
#define arep(arrat) for (const auto &value : array)
using namespace std;

bool sortinrev(const int &a, const int &b)
{
    return (a > b);
}

int main()
{
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vvi a(m, vi(n));
        rep(i, m)
        {
            rep(j, n)
                    cin >>
                a[i][j];
        }
        int flag =  0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i>0 && j>0 && i<m-1 && j<n-1){
                    if(a[i][j] > 4){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 4;
                    }
                }
                if(i == 0 && j>0 && j<n-1){
                    if(a[i][j] > 3){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 3;
                    }
                }
                if(i == m-1 && j>0 && j<n-1){
                    if(a[i][j] > 3){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 3;
                    }
                }
                if(j == 0&&i>0 && i<m-1){
                    if(a[i][j] > 3){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 3;
                    }
                }
                if(j == n-1 && i>0 && i<m-1){
                    if(a[i][j] > 3){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 3;
                    }
                }
                if( i==0&&j==0 || i ==0&&j==n-1){
                    if(a[i][j] > 2){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 2;
                    }
                }
                if(i == m-1 && j==n-1 || i == m-1 && j == 0){
                    if(a[i][j] > 2){
                        flag = 1;
                        break;
                    }
                    else {
                        a[i][j] = 2;
                    }
                }
            }
            if(flag)
            break;
        }
        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            rep(i,m){
                rep(j, n){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
