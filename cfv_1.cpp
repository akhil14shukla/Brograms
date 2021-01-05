#include <iostream>
#include <iomanip>
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
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

// string trans(string A, int d){
// }

int main()
{
    // std::ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //use auto instead of data types
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> A;
        unordered_set<int> s2;
        rep(i, n)
        {
            string s;
            cin >> s;
            bitset<60> b1(s);
            A.push_back(b1.to_ulong());
            s2.insert(A[i]);
        }
        int final = (pow(2, k) - 1) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (final >= A[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        string end;
        while (count != 0 || s2.find(final) !=s2.end())
        {
            if (count <= 0)
            {
                if (s2.find(final) == s2.end())
                {
                    count++;
                }
                final--;
            }
            else if(count > 0)
            {
                if (s2.find(final + 1) == s2.end())
                {
                    count--;
                }
                final++;
            }
        }
        int j = 0;
        while (final != 0)
        {
            if (final % 2 == 1)
            {
                end = '1' + end;
            }
            else
            {
                end = '0' + end;
            }
            final = final / 2;
            j++;
        }
        while (j < k)
        {
            end = '0' + end;
            j++;
        }
        cout <<end<<endl;
    }
    return 0;
}
