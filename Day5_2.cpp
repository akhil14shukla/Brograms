#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <math.h>
#include <stack>
using namespace std;

int solve(int A, int B, int C)
{
    int i, j;
    if (A == 0 || B == 0)
    {
        return 0;
    }
    if (A <= B)
    {
        i = A;
        j = B;
    }
    else
    {
        i = B;
        j = A;
    }
    if (C >= 2 * i - j)
    {
        return i;
    }

    long long final = j - i + C;
    long leftA = 2 * i - j - C; // of A
    long leftB = 2 * i - j - C; // of B
    if (leftA >= 3 && leftB >= 3)
    {
        int k = leftA / 3;
        leftA = leftA - 3 * k;
        leftB = leftB - 3 * k;
        final = final + 2 * k;
    }
    if ((leftA >= 1 && leftB > 1) || (leftA > 1 && leftB >= 1))
    {
        final = final + 1;
    }
    return final;
}

int main()
{
    cout << solve(40530425, 36939040, 14216346);
    return 0;
}
