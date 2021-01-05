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


int hIndex(vector<int>& citations) {
    // if (citations.size() !=0 && citations[0]!=0) {
    //     citations.insert(citations.begin(), 0);
    // }
    if (citations.size()!=0) {
        vector<int> final ={ 0 };
        int j = 0, i = 0;
        if (citations[0]==0) {
            i=0;
        }
        int n = citations.size();
        while (i<=citations.back() && j<n) {
            if (i<=citations[j]) {
                // dp[i] = n-j;
                if (i == n-j) {
                    final.push_back(i);
                }
            }
            if (j<n && i == citations[j]) {
                j++;
                // while (i == citations[j] && j<n) {
                //     j++;
                // }
            }
            i++;
        }
        return *max_element(final.begin(), final.end());
    }
    return 0;
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    int n;
    vector<int> a ={ 1,1 };
    // rep(i, n) {
    //     cin>>a[i];
    // }
    // // vector<int> dp(a[n-1]+1,0);
    // vector<int> final;
    // int j = 0;
    // rep(i, a[n-1]+1) {
    //     if (i<a[j]) {
    //         // dp[i] = n-j;
    //         if (i == n-j) {
    //             final.push_back(i);
    //         }
    //     }
    //     if (i == a[j]) {
    //         j++;
    //         while (i == a[j]) {
    //             j++;
    //         }
    //     }
    // }
    // cout<<*max_element(final.begin(), final.end())<<endl;
    cout<<hIndex(a);

    return 0;
}