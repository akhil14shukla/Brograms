#include <iostream>
#include<iomanip>
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
#define rep2(i, a, b) for (ll i = a; i <= b; i++)
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

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    unordered_map<int,vector<int>> m;
    rep(i,n-1){
        int t;
        int x;
        cin>>t>>x;
        m[t].pb(x);
        m[x].pb(t);
    }
    int flag = 1;
    unordered_map<int,vector<int>>::iterator m2;
    for(m2 = m.begin();m2!=m.end();m2++){
        int i = 0;
        int count = m2->second.size();
        // while(i<m2->second.size()){
        //     if(m.find(m2->second[i]) == m.end()){
        //         count++;
        //     }
        //     i++;
        // }
        if(count==2){
            cout<<"NO";
            // return 0;
            flag = 0;
            break;
        }
    }
    if(flag){
        cout<<"YES";
    }
    
    return 0;
}















 {
        int st = 1;
        rep(l, 2)
        {
            unordered_set<int> s;
            vector<bool> set(n + 1, 0);
            vector<int> u;
            set[0] = true;
            queue<int> q;
            q.push(st);
            while (!q.empty())
            {
                int curr = q.front();
                int flag2 = 1;
                set[curr] = 1;
                q.pop();
                rep(i1, n + 1)
                {
                    if (m[curr][i1] == 1 && s.find(i1) == s.end() && !set[i1])
                    {
                        q.push(i1);
                    }
                }
                rep(i1, u.size())
                {
                    if (m[curr][u[i1]] == 1)
                    {
                        flag2 = 0;
                    }
                }
                if (flag2)
                {
                    u.pb(curr);
                    s.insert(curr);
                }
                if (u.size() >= f)
                {
                    cout << 1 << el;
                    rep(l, f)
                    {
                        cout << u[l] << " ";
                    }
                    return 0;
                }
            }
            u.clear();
            rep(b, n + 1)
            {
                if (m[1][b] == 1 && b != 1)
                {
                    st = b;
                    break;
                }
            }
        }
    }