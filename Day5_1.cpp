#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;
double Arrays(const vector<int> &A, const vector<int> &B)
{
    int i, j;
    int m = (A.size()) / 2;
    int n = (B.size()) / 2;
    if (A.size() != 0 && B.size() != 0)
    {
        while (max(A[m - 1], B[n-1]) > min(A[m], B[n]) && (m - 1) >= 0 && (n - 1) >= 0 && m < A.size() && n < B.size())
        {
            if (A[m - 1] > B[n-1])
            {
                m--;
                n++;
            }
            else
            {
                m++;
                n--;
            }
        }
        int left = m + n;
        int right = A.size() - m + B.size() - n ;
        if (left > right)
        {
            return max(A[m - 1], B[n-1]);
        }
        if (right > left)
        {
            return min(B[n], A[m]);
        }
        return double(double(max(A[m - 1], B[n-1]) + min(B[n], A[m])) / 2);
    }
    if (A.size() == 0)
    {
        if (B.size() % 2 == 0)
        {
            return double(double(B[B.size() / 2] + B[B.size() / 2 - 1]) / 2);
        }
        else
        {
            return B[B.size() / 2];
        }
    }
    if (A.size() % 2 == 0)
    {
        return double(double(A[A.size() / 2] + A[A.size() / 2 - 1]) / 2);
    }
    else
    {
        return A[A.size() / 2];
    }
}
int main()
{
    vector<int> A = {-40, -25, 5, 10, 14, 28, 29, 48};
    vector<int> B = {-48, -31, -15, -6, 1, 8};
    cout << Arrays(A, B) << endl;
    return 0;
}

