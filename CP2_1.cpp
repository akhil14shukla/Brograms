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
        int n;
        cin>>n;
        vector<int> A(n);
        rep(i, n){
            int temp;
            cin>>temp;
            A[i] = temp;
        }
        int flag = 1;
        int check = 0;
        vector<int> B = A;
        sort(A.begin(),A.end());
        if(A == B){
            cout<<0<<endl;
            continue;
        }
        sort(A.begin(),A.end(),sortinrev);
        if(A == B){
            cout<<0<<endl;
            continue;
        }
        for(int i = n-1;i>0;i--){
            if(check == 0){
                if(B[i]>B[i-1]){
                    check++;
                }
            }
            else if(check == 1){
                if(B[i]<B[i-1]){
                    check++;
                }
            }
            if(check>1){
                flag = 0;
                cout<<i<<endl;
                break;
            }
        }
        if(flag){
            cout<<0<<endl;
        }
    }
    return 0;
}
