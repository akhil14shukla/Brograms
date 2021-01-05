#include <iostream>
#include <vector>
#include <fstream>
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
#define vpair vector<pair<long, long>>
#define mp make_pair
#define d (int)1e9 + 7
#define INF (int)2e9 + 1
#define el "\n"
using namespace std;

bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second > b.second);
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
    int f;
    ofstream Out("output.txt");
    cin>>f;
    int l = 1;
    while (l<=f)
    {
        int n;
        cin >> n;
        string I;
        string O;
        cin >> I;
        cin >> O;
        vector<deque<string>> final(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    final[i].pb("Y");
                }
                else if(j>i)
                {
                    if (final[i][final[i].size()-1] == "Y" && O[j - 1] == 'Y' && I[j] == 'Y')
                    {
                        final[i].pb("Y");
                    }
                    else
                    {
                        final[i].pb("N");
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i-1; j >= 0; j--)
            {
                if(final[i][0] == "Y" && O[j+1] == 'Y'&&I[j] == 'Y'){
                    final[i].push_front("Y");
                }
                else{
                    final[i].push_front("N");
                }
            }
        }
        Out<<"Case #"<<l<<":"<<el;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
               Out<< final[i][j];
            }
            Out<<el;
        }
        l++;
    }
    return 0;
}
