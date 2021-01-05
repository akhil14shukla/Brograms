#include <bits/stdc++.h>
#include <stack>
using namespace std;
vector<int> slidingMaximum(const vector<int> &A, int B)
{
    deque<int> d;
    vector<int> f;
    d.push_back(0);
    int i = 0;
    for (i = 0; i < B && i < A.size(); i++)
    {
        while (!d.empty() && d.front() <= i - B)
        {
            d.pop_front();
        }
        if (d.empty())
        {
            d.push_front(i);
        }
       if (A[i] < A[d.front()])
        {
            if (A[i] < A[d.front()])
            {
                while (!d.empty() && A[i] > A[d.back()])
                {
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        else 
        {
            while(!d.empty()){
                d.pop_back();
            }
            d.push_front(i);
        }
    }
    // i++;
    f.push_back(A[d.front()]);
    for (; i <= A.size() - 1; i++)
    {
        while (!d.empty() && d.front() <= i - B)
        {
            d.pop_front();
        }
        if (d.empty())
        {
            d.push_front(i);
        }
        if (A[i] < A[d.front()])
        {
            if (A[i] < A[d.front()])
            {
                while (!d.empty() && A[i] > A[d.back()])
                {
                    d.pop_back();
                }
                d.push_back(i);
            }
        }
        else 
        {
            while(!d.empty()){
                d.pop_back();
            }
            d.push_front(i);
        }

        f.push_back(A[d.front()]);
    }
    return f;
}

int main()
{
    vector<int> A = {648, 614, 490, 138, 657, 544, 745, 582, 738, 229, 775, 665, 876, 448, 4, 81, 807, 578, 712, 951, 867, 328, 308, 440, 542, 178, 637, 446, 882, 760, 354, 523, 935, 277, 158, 698, 536, 165, 892, 327, 574, 516, 36, 705, 900, 482, 558, 937, 207, 368};
    vector<int> B = slidingMaximum(A, 9);
    for (int i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
    }
    return 0;
}
