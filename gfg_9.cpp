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


int binary(vector<int> A, int k, int flag, int j) {
    int start = 0;
    int end = A.size()-1;
    int mid = (end - start)/2;
    while (start<=end) {
        mid = start + (end - start)/2;
        if (A[mid]<k) {
            start = mid + 1;
        }
        else if (A[mid]>k) {
            end = mid - 1;
        }
        // else if(A[end] == k){
        //     if(flag == 0){
        //         return end;
        //     }
        //     else if(flag == 2){
        //         return end+1;
        //     }
        // }
        else if (A[mid] == k) {
            if(flag == 0){
                while(A[mid]!=k && mid<A.size()){
                    mid--;
                }
                return mid+1;
            }
            else if(flag == 2){
                while(A[mid]!=k && mid < A.size()){
                    mid++;
                }
                return mid;
            }
        }
        // else if (start == end) {
        //     return mid;
        // }
    }
    return start;
}

int findMedian(vector<vector<int> > &A) {
    //     int i,j;
    //     int m = A.size();
    //     int n = A[0].size();
    //   int a[n*m];
    //   for(i = 0;i<m;i++){
    //       for(j = 0;j<n;j++){
    //           a[i*n+j] = A[i][j];
    //       }
    //   }
    //   sort(a,a+n*m);
    //   return a[n*m/2];
    int n = (A.size()*A[0].size() - 1)/2;
    for (int i = 0;i<A.size();i++) {
        for (int j = 0;j<A[0].size();j++) {
            int sum = 0;
            for (int k = 0;k<A.size();k++) {
                if (k<i) {
                    sum += binary(A[k], A[i][j], 2, j);
                }
                else if (k == i) {
                    sum += j;
                }
                else {
                    sum += binary(A[k], A[i][j], 0, j);
                }
            }
            if (sum == n) {
                return A[i][j];
            }
        }
    }
}


int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    vector<vector<int>> A ={ { 39979, 125437, 125437, 203623, 203623, 203779, 203779, 264692, 264692, 269989, 270755 },
        { 118788, 118788, 125437, 203623, 236410, 236410, 269989, 269989, 269989, 270755, 270755 },
        { 118788, 118788, 125437, 125437, 202832, 203623, 203623, 203779, 203779, 264692, 270755 } };
    cout<<findMedian(A);

    return 0;
}