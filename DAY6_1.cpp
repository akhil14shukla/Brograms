#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#include <string>
#define pb push_back
#define pop pop_back
#define ll long long int
#define vi vector<int>
#define vl vector<long>
using namespace std;

int drome(string A)
{
    int i = 0;
    int j = A.size() - 1;
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    while (i <= j)
    {
        if (((A[i] >= 97 && A[i] <= 122) || (A[i]>=48 && A[i]<=57)) && ((A[j] >= 97 && A[j] <= 122) || (A[j]>=48 && A[j]<=57)))
        {
            if (A[i] != A[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        else
        {
            if (!(((A[i] >= 97 && A[i] <= 122) || (A[i]>=48 && A[i]<=57))))
                i++;
            if (!((A[j] >= 97 && A[j] <= 122) || (A[j]>=48 && A[j]<=57)))
                j--;
        }
    }
    return 1;
}

int main()
{
    string A = "a1kk,1a";
    cout<<drome(A);

    return 0;
}