#include <iostream>
#include <vector>
using namespace std;


int maxSpecialProduct(vector<int> &A)
{
    int i, j;
    vector<int> max;
    max.push_back(0);
    for (i = 0; i < A.size(); i++)
    {
        int m = 0, n = 0;
        for (j = i - 1; j >= 0; j--)
        {
            if (A[i] < A[j])
            {
                m = j;
                break;
            }
        }
        for (j = i + 1; j < A.size(); j++)
        {
            if (A[i] < A[j])
            {
                n = j;
                break;
            }
        }
        if (max[0] < m * n)
        {
            max[0] = m*n;
        }
    }

    return max[0] % 1000000007;
}

int main()
{
    vector<int> A = {9 , 8, 1, 2, 3, 5, 9};
    int final = maxSpecialProduct(A);
    cout << final;
    return 0;
}