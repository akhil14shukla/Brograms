#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

// int count_set_bit(int n)
// {
//     int count = 0;
//     while (n != 0)
//     {
//         if (n & 1 == 1)
//         {
//             count++;
//         }
//         n = n >> 1; //right shift 1 bit
//     }
//     return count;
// }
vector<int> getMode(vector<int> &A, vector<vector<int>> &B)
{
    map<int, set<int>, greater<int>> m;
    vector<int> final;
    unordered_map<int, int> m2;
    for (int i = 0; i < A.size(); i++)
    {
        m2[A[i]]++;
    }
    // unordered_map<int, int>::iterator mit;
    for (auto mit = m2.begin(); mit != m2.end(); mit++)
    {
        m[mit->second].insert(mit->first);
    }
    for (int i = 0; i < B.size(); i++)
    {
        int temp11 = m2[A[B[i][0] - 1]];
        int temp12 = A[B[i][0] - 1];
        int temp21 = m2[B[i][1]];
        int temp22 = B[i][1];
        m[temp11].erase(temp12);
        if(m[temp11].empty()){
            m.erase(temp11);
        }
        m[temp21].erase(temp22);
        if(m[temp21].empty()){
            m.erase(temp21);
        }
        m[temp11 - 1].insert(temp12);
        m[temp21 + 1].insert(temp22);
        m2[A[B[i][0] - 1]]--;
        m2[B[i][1]]++;
        A[B[i][0] - 1] = B[i][1];
        final.push_back(*(m.begin()->second.begin()));
    }
    return final;
}

int main()
{

    vector<int> A = {2, 2, 2, 3, 3,4,4,4};
    vector<vector<int>> B = {{1, 4}, {5, 2}, {4, 2}};
    vector<int> C = getMode(A, B);
    for (int i = 0; i < C.size(); i++)
    {
        cout << C[i] << " ";
    }
    return 0;
}