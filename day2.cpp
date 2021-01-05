#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(int A)
{
    int a = 1;
    vector<vector<int>> A1;
    if (A > 0)
    {
        int i, j;
        vector<int> intial;
        intial.push_back(1);
        A1.push_back(intial);

        for (i = 2; i <= A; i++)
        {
            vector<int> temp;
            temp.push_back(1);
            for (j = 1; j < A1[i - 2].size(); j++)
            {
                temp.push_back(A1[i - 2][j] + A1[i - 2][j - 1]);
            }
            temp.push_back(1);
            A1.push_back(temp);
        }
        return A1;
    }
    return {};
}

int main()
{
    vector<vector<int>> final = solve(5);
    cout << final[0][0];
    return 0;
}