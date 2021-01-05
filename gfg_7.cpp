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
bool isPrime(int n)
{
    // Corner cases 
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
            return false;

    return true;
}
bool check(string s, string curr, int start) {
    int k = 0;
    while (k<curr.size()) {
        if (curr[k] != s[k+start]) {
            return false;
        }
        k++;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        vector<vector<int>> dp(s.size(), vector<int>(2, 1e9+7));
        string curr;
        curr.push_back(s[0]);
        // dp[1][0] = 1;
        dp[0][0] = 1;
        // int count = 1;
        rep2(i, 1, s.size()-1) {
            if (check(s, curr, i)) {
                // int k = 0;
                // while (k<curr.size()) {
                //     dp[i+k][1] = min(dp[i+k][1], min(dp[i-1][1], dp[i-1][0])+1);
                //     dp[i+k][0] = min(dp[i+k-1][0] + 1, dp[i+k][0]);
                //     k++;
                // }
                // i = 2*curr.size();
                dp[i+curr.size()-1][1] = min(dp[i-1][1],dp[i-1][0])+1;
                dp[i][0] = min(dp[i-1][1],dp[i-1][0])+1;
                curr.push_back(s[i]);
            }
            else {
                // count++;
                dp[i][0] = min(dp[i-1][1],dp[i-1][0])+1;
                curr.push_back(s[i]);
            }
        }
        cout<<min(dp[s.size()-1][0], dp[s.size()-1][1])<<endl;
    }

    return 0;
}