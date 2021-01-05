#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#define pb push_back
// #define pop pop_back
#define ll unsigned long long int
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

//over

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

int dfs(int n, vector<vector<int>> &adj, vector<bool> &check, vector<vector<ll>> &final1, int last)
{
    // if (n == target)
    // {
    //     check[target] = true;
    //     return final;
    // }
    for (int j = 0; j < adj[last].size(); j++)
    {
        if (adj[last][j] != 0 && !check[j])
        {
            check[j] = true;
            final1[n][j] = final1[n][last] + adj[last][j];
            dfs(n, adj, check, final1, j);
        }
        // if (check[target])
        // {
        //     return a;
        // }
    }
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    // int t;
    // cin >> t;
    // while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> a(n, vector<ll>(3, 0));
        int cons = 0;
        rep(i, n)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
        }
        vector<vector<ll>> dp(n, vector<ll>(3, 0));
        dp[0] = a[0];
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (dp[i][j] < dp[i - 1][k] + a[i][j] && !(j == k))
                    {
                        dp[i][j] =  dp[i - 1][k] + a[i][j];
                    }
                }
            }
        }
        cout << max(dp[n-1][0],max(dp[n-1][1].first, dp[n-1][2].first)) << endl;
    }
    return 0;
}




































































// #include <iostream>
// #include <iomanip>
// #include <vector>
// #include <bits/stdc++.h>
// #include <math.h>
// #include <stack>
// #define pb push_back
// // #define pop pop_back
// #define ll unsigned long long int
// #define vi vector<int>
// #define vl vector<long>
// #define vvi vector<vector<int>>
// #define vvl vector<vector<long>>
// #define rep(i, n) for (ll i = 0; i < n; i++)
// #define rep2(i, a, b) for (ll i = a; i <= b; i++)
// #define repr(i, a, b) for (ll i = a; i >= b; i--)
// #define I long_max
// #define pii pair<int, int>
// #define pll pair<long, long>
// #define vpair vector<pair<int, int>>
// #define mp make_pair
// #define all(v) v.begin(), v.end()
// #define rall(v) v.rbegin(), v.rend()
// #define fir first
// #define sec second
// #define d (int)1e9 + 7
// #define INF (int)2e9 + 1
// #define el "\n"
// #define fs fastscan

// #define vrep(vec) for (const auto &value : vec)
// #define arep(arrat) for (const auto &value : array)
// using namespace std;

// bool sortinrev(const pair<int, int> &a,
//                const pair<int, int> &b)
// {
//     return (a.first > b.first);
// }
// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }

// //over

// bool isPrime(int n)
// {
//     // Corner cases
//     if (n <= 1)
//         return false;
//     if (n <= 3)
//         return true;

//     // This is checked so that we can skip
//     // middle five numbers in below loop
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;

//     for (int i = 5; i * i <= n; i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;

//     return true;
// }

// int dfs(int n, vector<vector<int>> &adj, vector<bool> &check, vector<vector<ll>> &final1, int last)
// {
//     // if (n == target)
//     // {
//     //     check[target] = true;
//     //     return final;
//     // }
//     for (int j = 0; j < adj[last].size(); j++)
//     {
//         if (adj[last][j] != 0 && !check[j])
//         {
//             check[j] = true;
//             final1[n][j] = final1[n][last] + adj[last][j];
//             dfs(n, adj, check, final1, j);
//         }
//         // if (check[target])
//         // {
//         //     return a;
//         // }
//     }
//     return 0;
// }

// int main()
// {
//     std::ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     //use auto instead of data types
//     // int t;
//     // cin >> t;
//     // while (t--)
//     {
//         ll n;
//         cin >> n;
//         vector<vector<ll>> a(n, vector<ll>(3, 0));
//         int cons = 0;
//         rep(i, n)
//         {
//             cin >> a[i][0] >> a[i][1] >> a[i][2];
//         }
//         vector<vector<pair<ll, int>>> dp(n, vector<pair<ll, int>>(3, {0, 0}));
//         dp[0][0] = {a[0][0], -1};
//         dp[0][1] = {a[0][1], -1};
//         dp[0][2] = {a[0][2], -1};
//         for (int i = 1; i < n; i++)
//         {
//             for (int j = 0; j < 3; j++)
//             {
//                 for (int k = 0; k < 3; k++)
//                 {
//                     if (dp[i][j].first < dp[i - 1][k].first + a[i][j] && !(k==dp[i-1][k].second && k==j))
//                     {
//                         dp[i][j].first =  dp[i - 1][k].first + a[i][j];
//                         dp[i][j].second = k;
//                     }
//                 }
//             }
//         }
//         cout << max(dp[n-1][0].first,max(dp[n-1][1].first, dp[n-1][2].first)) << endl;
//     }
//     return 0;
// }
