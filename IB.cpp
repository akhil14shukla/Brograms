#include <bits/stdc++.h>
#include <vector>
using namespace std;

int search(const vector<int> &A, int B)
{
    if (B == A[0])
    {
        return 0;
    }
    if (B == A[A.size() - 1])
    {
        return A.size() - 1;
    }
    if (A[0] < A[A.size() - 1])
    {
        int low1 = 0;
        int high1 = A.size() - 1;
        int flag1 = 0;
        int final1 = 0;
        while (low1 <= high1)
        {
            int mid = low1 + (high1 - low1) / 2;
            if (B == A[mid])
            {
                flag1 = 1;
                final1 = mid;
                break;
            }
            if (B > A[mid])
            {
                low1 = mid + 1;
            }
            if (B < A[mid])
            {
                high1 = mid - 1;
            }
        }
        if (flag1 == 1)
        {
            return final1;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        if (B >= A[0] && B >= A[A.size() - 1] || B <= A[0] && B <= A[A.size() - 1])
        {
            int i = 0;
            while (A[i] < A[i + 1] && i < A.size())
            {
                i++;
            }
            int m = i;
            int low = 0;
            int high = i;
            int flag = 0;
            int final = 0;
            if(B>=A[0] && B<=A[i]){
                low = 0;
                high = i;
            }
            else if(B>=A[i+1] && B<=A[A.size()-1]){
                low = i+1;
                high = A.size()-1;
            }
            else{
                return -1;
            }
            while (low <= high)
            {
                int mid = low + (high - low) / 2;
                if (B == A[mid])
                {
                    flag = 1;
                    final = mid;
                    break;
                }
                if (B > A[mid])
                {
                    low = mid + 1;
                }
                if (B < A[mid])
                {
                    high = mid - 1;
                }
            }
            if (flag == 1)
            {
                return final;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            return -1;
        }
    }
}
int main()
{
    vector<int> A = {180, 181, 182, 183, 184, 187, 188, 189, 191, 192, 193, 194, 195, 196, 201, 202, 203, 204, 3, 4, 5, 6, 7, 8, 9, 10, 14, 16, 17, 18, 19, 23, 26, 27, 28, 29, 32, 33, 36, 37, 38, 39, 41, 42, 43, 45, 48, 51, 52, 53, 54, 56, 62, 63, 64, 67, 69, 72, 73, 75, 77, 78, 79, 83, 85, 87, 90, 91, 92, 93, 96, 98, 99, 101, 102, 104, 105, 106, 107, 108, 109, 111, 113, 115, 116, 118, 119, 120, 122, 123, 124, 126, 127, 129, 130, 135, 137, 138, 139, 143, 144, 145, 147, 149, 152, 155, 156, 160, 162, 163, 164, 166, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177};
    cout << search(A, 42) << endl;
}
