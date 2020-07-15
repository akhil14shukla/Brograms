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

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int Length(ListNode *first)
{
    ListNode *temp = first;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int Delete(ListNode *A, int index)
{
    ListNode *temp, *count;
    int x;

    /*if (index < 0 || index > Length())
    {
        return -1;
    }*/
    if (index == 1)
    {
        temp = A;
        A = A->next;
        x = temp->val;
        delete temp;
    }
    else
    {
        count = A;
        for (int i = 0; i < index - 1; i++)
        {
            temp = count;
            count = count->next;
        }
        temp->next = count->next;
        x = count->val;
        delete count;
    }
}
ListNode *deleteDuplicates(ListNode *A)
{
    int i = 0;
    ListNode *A1 = A;
    while (A->next != NULL)
    {
        if (A1->val == A1->next->val)
        {
            Delete(A, i + 1);
        }
        else
        {
            A1 = A1->next;
            i++;
        }
    }
    return A;
}

int main()
{

    ListNode *A = {1 -> 1 -> 1 -> 1 -> 1 -> 1 -> 1};
}