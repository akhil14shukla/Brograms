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

int gen(int num, int k)
{
    int fin = 0;
    for (int i = 0; i < num; i++)
    {
        fin = fin + k * pow(10, i);
    }
    return fin;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int n;
    cin >> n;
    unordered_map<int, int> m;
    vi a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[i + 1] = a[i];
    }
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> s;
        //    s.insert(i+1);
        int k = 0;
        int curr = i + 1;
        for (int j = 0; j < 3; j++)
        {
            if (k == 2 && m[curr] == i+1){
                cout<<"YES"<<el;
                flag = 0;
                break;
            }
            if (s.find(m[curr]) == s.end())
            {
                curr = m[curr];
                s.insert(curr);
                k++;
                continue;
            }
            
        }
        if(!flag){
            break;
        }
    }
    if(flag){
        cout<<"NO";
    }
    return 0;
}
