#include <bits/stdc++.h>
using namespace std;

bool sir(string &a, string &b)
{
    int i = 0;
    string a1 = a + b;
    string b1 = b + a;
    for (i = 0; i < a1.size(); i++)
    {
        if (a1[i] > b1[i])
        {
            return true;
        }
        if (a1[i] < b1[i])
        {
            return false;
        }
    }
    return true;
    // if (i == a.size())
    // {
    //     if (b[i] < b[i -1])
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
    // if (a[i] < a[i - 1])
    // {
    //     return false;
    // }
    // else
    // {
    //     return true;
    // }
}

string maximumGap(const vector<int> &A)
{
    vector<string> a(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        a[i] = to_string(A[i]);
    }
    sort(a.begin(), a.end(), sir);
    string final;
    if (a[0] == "0")
    {
        return "0";
    }
    for (int j = 0; j < a.size(); j++)
    {
        final += a[j];
    }
    return final;
}

int main()
{
    // vector<int> A = {3, 30, 34, 5, 9};
    vector<int> A = {9, 99, 999, 9999, 9998};
    cout << maximumGap(A) << endl;
}
