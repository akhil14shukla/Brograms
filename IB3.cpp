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

int count(int A)
{
    int count1 = 0;
    int temp = A;
    while (temp != 0)
    {
        count1 = count1 + temp % 2;
        temp = temp / 2;
    }
    return count1;
}

int cntBits(vector<int> &A)
{
    sort(A.begin(), A.end());
    int count1 = 0;
    int count0 = 0;
    int final = 0;
    while (A[A.size() - 1] != 0)
    {
        for (int j = 0; j < A.size(); j++)
        {
            if (A[j] % 2 == 0)
            {
                count0++;
            }
            else
            {
                count1++;
            }
            A[j] = A[j] / 2;
        }
        final = final + 2 * count0 * count1;
        count0 = 0;
        count1 = 0;
    }
    return final;
}

int main()
{
    vector<int> A = /*{1,3,5};*/{47, 60, 23, 88, 5};
    vector<int> final = A;
    cout << cntBits(A);
    return 0;
}