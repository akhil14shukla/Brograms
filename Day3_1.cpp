#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

int bs(vector<pair<int, int>> a, int i, int initial, int n)
{ // intial n is a.size()
    if (a[n / 2].second >= i && i < a[n / 2 - 1].second)
    {
        return a[n / 2].first;
    }
    else if (i > a[n / 2].second)
    {
        return bs(a, i, n / 2, n);
    }

    return bs(a, i, initial, n / 2);
}
bool sortinrev(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.first > b.first);
}
vector<int> solve(vector<int> &A, vector<int> &B)
{
    vector<pair<long long, long long>> a;
    int i, j;
    int count1 = 0, count2 = 0;
    for (i = 0; i < A.size(); i++)
    {
        count1 = 1;
        count2 = 0;
        for (j = i - 1; j >= 0; j--)
        {
            if (A[j] < A[i])
            {
                count1++;
            }
            if (A[i] <= A[j])
            {
                break;
            }
        }
        for (j = i; j < A.size(); j++)
        {
            if (A[i] >= A[j])
            {
                count2++;
            }
            if (A[i] < A[j])
            {
                break;
            }
        }
        a.push_back(make_pair(A[i], count1 * count2));
    }
    for (i = 0; i < a.size(); i++)
    {
        int temp = a[i].first;
        for (j = ceil(temp / 2); j > 0; j--)
        {
            if (temp % j == 0)
            {
                a[i].first = (a[i].first * j) % 1000000007;
            }
        }
        a[i].first = a[i].first % 1000000007;
    }

    sort(a.begin(), a.end(), sortinrev);
    for (i = 1; i < a.size(); i++)
    {
        a[i].second = a[i].second + a[i - 1].second;
    }
    vector<int> final1(B.size());
    int low, high;
    for (i = 0; i < B.size(); i++)
    {
        low = 0;
        high = a.size() - 1;
        while (low <= high)
        {
            int mid1 = a[low + (high - low) / 2].second;
            int mid2 = a[low + (high - low) / 2 + 1].second;
            int mid3 = a[low + (high - low) / 2 - 1].second;
            if ((B[i] > mid1 && B[i] <= mid2))
            {
                final1[i] = a[low + (high - low) / 2 + 1].first;
                break;
            }
            if ((B[i] <= mid1 && B[i] > mid3))
            {
                final1[i] = a[low + (high - low) / 2].first;
                break;
            }
            if (B[i] > mid1)
            {
                low = low + (high - low) / 2 + 1;
            }
            if (B[i] < mid1)
            {
                high = low + (high - low) / 2 - 1;
            }
        }
    }
    return final1;
}
int main()
{
    vector<int> A = {39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45};
    vector<int> B = {1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838};
    vector<int> C = solve(A, B);
    for (int i = 0; i < C.size(); i++)
    {
        cout << C[i];
    }
    return 0;
}