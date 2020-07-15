#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> nextPermutation(vector<int> &A)
{
    int i, j;
    int m = A[A.size() - 1];
        int min = 0;
    int start = 0;
    int flag = 0;
    for (j = A.size() - 1; j > 0; j--)
    {
        m = A[j];
        if (A[j - 1] < m)
        {
            min = j - 1;
            i= j;
            flag = 1;
            break;
        }
    }
    for (j = A.size()-1; j >min && flag == 1; j--)
    {
        if (A[j] > A[min])
        {
            i = j;
            break;
        }
    }
    if (A.size() != 1)
    {
        int temp = A[min];
        A[min] = A[i];
        A[i] = temp;
        if(flag){
        sort(A.begin() + min+1, A.end()); 
        }
        if(flag){
        sort(A.begin() , A.end()); 
        }
    }
    return A;
}

int main()
{
    vector<int> A = { 251, 844, 767, 778, 658, 337, 10, 252, 632, 262, 707, 506, 701, 475, 410, 696, 631, 903, 516, 149, 344, 101, 42, 891, 991};

    vector<int> final = nextPermutation(A);
    for (int i = 0; i < final.size(); i++)
        cout << final[i] << ", ";
    return 0;
}