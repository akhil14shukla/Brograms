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
        fin =fin+ k * pow(10, i);
    }
    return fin;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int temp = n;
        int num = 0;
        while (temp != 0)
        {
            num++;
            temp = temp / 10;
        }
        int final = (num-1)*9;
        for(int i = 1;i<=9;i++){
            if(gen(num,i)<=n){
                final++;
            }
            else{
                break;
            }
        }
        cout<<final<<el;
    }
    return 0;
}
