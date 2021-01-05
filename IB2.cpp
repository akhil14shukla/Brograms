#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
#define pb push_back
// #define pop pop_back
using namespace std;

vector<string> Str(vector<string> &A, int B)
{
    int n = A.size();
    int i = 0;
    int sum = 0;
    int j, k;
    int count = 0;
    vector<string> final;
    for (j = 0; j < A.size(); j++)
    {
        sum = 0;
        for (i = j; i < n; i++)
        {
            if (sum + A[i].size() < B - i + j + 1)
                sum = sum + A[i].size();
            else
            {
                break;
            }
        }
        int extra = B - sum;
        int num = i - j;
        int each = extra;
        int left = 0;
        if (num > 1)
        {
            each = extra / (num - 1);
            left = extra % (num - 1);
        }
        for (i = 0; i < num; i++)
        {
            if (left>0 && num + j < A.size())
            {
                for (k = 0; k < 1 + each; k++)
                {
                    A[i + j].append(" ");
                }
                extra = extra - 1 - each;
                left--;
                if(extra<=0)
                break;
            }
            else if (left<=0 && num + j < A.size())
            {
                for (k = 0; k < each; k++)
                {
                    A[i + j].append(" ");
                }
                extra = extra - each;
                if(extra<=0)
                break;
            }
            else
            {
                if (extra > 0 && num + j == A.size()&&i<num-1)
                {
                    A[i + j].append(" ");
                    extra--;
                }
                else if (extra > 0 && i + j == A.size() - 1)
                {
                    for (k = 0; k < extra; k++)
                    {
                        A[i + j].append(" ");
                    }
                    break;
                }
            }
        }
        j = j + num - 1;
    }
    count = 0;
    sum = 0;
    final.push_back("");
    for (i = 0; i < n; i++)
    {
        if (sum + A[i].size() <= B)
        {
            sum = sum + A[i].size();
            final[count].append(A[i]);
        }
        if (sum == B)
        {
            sum = 0;
            final.push_back("");
            count++;
        }
    }
    if (final[final.size() - 1].size() == 0)
    {
        final.pop_back();
    }
    return final;
}

int main()
{
    vector<string> A =  { "glu", "muskzjyen", "ahxkp", "t", "djmgzzyh", "jzudvh", "raji", "vmipiz", "sg", "rv", "mekoexzfmq", "fsrihvdnt", "yvnppem", "gidia", "fxjlzekp", "uvdaj", "ua", "pzagn", "bjffryz", "nkdd", "osrownxj", "fvluvpdj", "kkrpr", "khp", "eef", "aogrl", "gqfwfnaen", "qhujt", "vabjsmj", "ji", "f", "opihimudj", "awi", "jyjlyfavbg", "tqxupaaknt", "dvqxay", "ny", "ezxsvmqk", "ncsckq", "nzlce", "cxzdirg", "dnmaxql", "bhrgyuyc", "qtqt", "yka", "wkjriv", "xyfoxfcqzb", "fttsfs", "m"};
    vector<string> final = Str(A, 144);
    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i];
        cout<<endl;
    }
    // cout<<Palindrome("a");
    return 0;
}