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

//extra
void fastscan(int &number) //much faster way of input, only integers
{
    //variable to indicate sign of input number     //getchar_unlocked() fastest way of input  and lly, putchar_unlocked(c)
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
//over
int rec(int A, const vector<int> &B, const vector<int> &C, vector<vector<int>> &dp)
{
    if (A == 0)
    {
        return 0;
    }
    if (A < 0)
    {
        return INT_MAX - 10000;
    }
    int min2 = INT_MAX;
    for (int i = 0; i < B.size(); i++)
        if (A - B[i] >= 0)
        {
            if (dp[A - B[i]][i] == -1)
                dp[A - B[i]][i] = C[i] + rec(A - B[i], B, C, dp);
            min2 = min(min2, dp[A - B[i]][i]);
        }
    return min2;
}

int solve(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int final = 0;
    int max2 = 0;
    for (int i = 0; i < A.size(); i++)
    {
        max2 = max(max2, A[i]);
    }
    vector<int> dp(max2 + 1,INT_MAX);
    // for (int i = 0; i < A.size(); i++)
    // {
    //     dp[A[i]][B.size()]= rec(A[i], B, C, dp);
    //     final = final + dp[A[i]][B.size()] ;
    // }
    dp[0]=0;
    for(int i =0;i<B.size();i++){
        dp[B[i]]=min(dp[B[i]],C[i]);
    }
    for (int i = 2; i<=max2;i++){
        for(int j = 1;j<i;j++)
            dp[i]=min(dp[i],dp[i-j]+dp[j]);
    }
    for(int i = 0;i<A.size();i++){
        final = final + dp[A[i]];
    }
    return final;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //use auto instead of data types
    vector<int> a = {889, 57, 270, 195, 560, 21, 632, 520, 669, 651, 471, 530, 607, 390, 574, 675, 242, 454, 856, 320, 516, 393};
    vector<int> b = { 1, 994, 285, 886, 473, 996, 32, 266, 225, 920, 322, 494, 833, 601, 233, 465, 121, 621, 116, 310, 151, 441, 699, 443, 835, 660, 897, 691, 979, 132, 802, 346, 126, 87, 232, 317, 84, 981, 583, 27, 901, 623, 521, 453, 224, 472, 917, 345, 93, 752, 373, 961, 911, 73, 405, 746, 732, 21, 156, 430, 152, 957, 775, 277, 763, 725, 313, 565, 707, 895, 591, 327, 518, 830, 499, 742, 303, 135, 805, 114, 886};
    vector<int> c = {178, 794, 517, 968, 917, 981, 419, 937, 138, 848, 89, 813, 342, 84, 295, 786, 396, 859, 212, 10, 170, 257, 528, 999, 755, 988, 21, 890, 793, 135, 495, 689, 928, 12, 377, 845, 993, 795, 501, 849, 363, 589, 381, 423, 391, 676, 209, 787, 254, 420, 515, 423, 396, 43, 423, 151, 749, 443, 41, 261, 296, 536, 950, 942, 266, 327, 506, 977, 840, 7, 826, 203, 314, 926, 345, 705, 602, 553, 211, 574, 692 };
    // double f = double(a + b) / 2;
    cout << solve(a, b, c);

    return 0;
}
