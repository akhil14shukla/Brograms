#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int max(vector<int> A, int start, int end)
{
    int i, max = A[start];
    for (i = start; i <= end; i++)
    {
        if (max < A[i])
            max = A[i];
    }
    return max;
}
vector<int> solve(vector<int> &A, vector<int> &B)
{
    int i, j;
    vector<int> G;
    for (i = 0; i < A.size(); i++)
    {
        for (j = 0; j < A.size() ; j++)
        {
            G.push_back(max(A, i, j));
        }
    }
    for (i = 0; i < G.size(); i++)
    {
        int temp = G[i];
        for (j = temp / 2; j > 1; j--)
        {
            if (temp % j == 0)
                G[i] = G[i] * j;
        }
        G[i] = G[i] % 1000000007;
    }
    sort(G.begin(), G.end(), greater<int>());
    vector<int> final;
    for (i = 0; i < B.size(); i++)
    {
        final.push_back(G[B[i] - 1]);
    }
    return final;
}

int main()
{
    vector<int> A = {39, 99, 70, 24, 49, 13, 86, 43, 88, 74, 45, 92, 72, 71, 90, 32, 19, 76, 84, 46, 63, 15, 87, 1, 39, 58, 17, 65, 99, 43, 83, 29, 64, 67, 100, 14, 17, 100, 81, 26, 45, 40, 95, 94, 86, 2, 89, 57, 52, 91, 45};
    vector<int> B = {1221, 360, 459, 651, 958, 584, 345, 181, 536, 116, 1310, 403, 669, 1044, 1281, 711, 222, 280, 1255, 257, 811, 409, 698, 74, 838};
    vector<int> final = solve(A, B);
    ;
    for (int i = 0; i < final.size(); i++)
        cout << final[i] << ", ";
    return 0;
}