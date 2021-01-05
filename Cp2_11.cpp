#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
// #define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
#define vvi vector<vector<int>>
#define vvl vector<vector<long>>
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
#define repr(i, a, b) for (ll i = a; i >= b; i--)
#define I long_max
#define pii pair<int, int>
#define pll pair<long, long>
#define vpair vector<pair<int, int>>
#define mp make_pair
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}

void rec1(int t, int qx, int qy, vector<vector<bool>> &check)
{
    for (int i = 0; i <= t; i++)
    {
        check[qx][i] = false;
        check[i][qy] = false;
    }
    for (int j = 1; j <= t; j++)
    {
        if (qx + j <= t && qy + j <= t && qx + j >= 0 && qy + j >= 0)
        {
            check[qx + j][qy + j] = false;
        }
        if (qx - j <= t && qy - j <= t && qx - j >= 0 && qy - j >= 0)
        {
            check[qx - j][qy - j] = false;
        }
        if (qx + j <= t && qy - j <= t && qx + j >= 0 && qy - j >= 0)
        {
            check[qx + j][qy - j] = false;
        }
        if (qx - j <= t && qy + j <= t && qx - j >= 0 && qy + j >= 0)
        {
            check[qx - j][qy + j] = false;
        }
    }
}
// map<pair<int,int>, int> m;
int rec(int t, int kx, int ky,const int &tx,const int &ty,vector<vector<bool>> &check)
{
    stack<pair<int,int>> s;
    s.push(mp(kx,ky));
    set<pair<int,int>> s2;
    // s2.insert(mp(kx,ky));
    while(!s.empty()){
        int cx = s.top().first, cy = s.top().second;
        s2.insert(mp(cx,cy));
        s.pop();

        if(check[cx+1][cy+1] == true && s2.find(mp(cx+1,cy+1)) == s2.end() && cx+1 >0 && cx+1 <=t && cy+1 >0 && cy+1<=t){
            s.push(mp(cx+1, cy+1));
            s2.insert(mp(cx+1,cy+1));
            if(cx+1 == tx && cy+1 == ty){
                return 1;
            }
        }
        if(check[cx-1][cy-1] == true && s2.find(mp(cx-1,cy-1)) == s2.end() && cx-1 >0 && cx-1 <=t && cy-1 >0 && cy-1<=t){
            s.push(mp(cx-1, cy-1));
            s2.insert(mp(cx-1,cy-1));
            if(cx-1 == tx && cy-1 == ty){
                return 1;
            }
        }
        if(check[cx+1][cy-1] == true && s2.find(mp(cx+1,cy-1)) == s2.end()  && cx+1 >0 && cx+1 <=t && cy-1 >0 && cy-1<=t){
            s.push(mp(cx+1, cy-1));
            s2.insert(mp(cx+1,cy-1));
            if(cx+1 == tx && cy-1 == ty){
                return 1;
            }
        }
        if(check[cx-1][cy+1] == true && s2.find(mp(cx-1,cy+1)) == s2.end() && cx-1 >0 && cx-1 <=t && cy+1 >0 && cy+1<=t){
            s.push(mp(cx-1, cy+1));
            s2.insert(mp(cx-1,cy+1));
            if(cx-1 == tx && cy+1 == ty){
                return 1;
            }
        }
        if(check[cx+1][cy] == true && s2.find(mp(cx+1,cy)) == s2.end() && cx+1 >0 && cx+1 <=t && cy >0 && cy<=t){
            s.push(mp(cx+1, cy));
            s2.insert(mp(cx+1,cy));
            if(cx+1 == tx && cy == ty){
                return 1;
            }
        }
        if(check[cx-1][cy] == true && s2.find(mp(cx-1,cy)) == s2.end() && cx-1 >0 && cx-1 <=t && cy >0 && cy<=t){
            s.push(mp(cx-1, cy));
            s2.insert(mp(cx-1,cy));
            if(cx-1 == tx && cy == ty){
                return 1;
            }
        }
        if(check[cx][cy+1] == true && s2.find(mp(cx,cy+1)) == s2.end() && cx >0 && cx <=t && cy+1 >0 && cy+1<=t){
            s.push(mp(cx, cy+1));
            s2.insert(mp(cx,cy+1));
            if(cx == tx && cy+1 == ty){
                return 1;
            }
        }
        if(check[cx][cy-1] == true && s2.find(mp(cx,cy-1)) == s2.end() && cx >0 && cx <=t && cy-1 >0 && cy-1<=t){
            s.push(mp(cx, cy-1));
            s2.insert(mp(cx,cy-1));
            if(cx == tx && cy-1 == ty){
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;
    int qx, qy;
    cin >> qx >> qy;
    int kx, ky;
    cin >> kx >> ky;
    int tx, ty;
    cin >> tx >> ty;
    vector<vector<bool>> check(t + 10, vector<bool>(t + 10, true));
    rec1(t, qx, qy, check);
    // set<pair<int, int>> s;
    if (rec(t, kx, ky, tx, ty, check))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
