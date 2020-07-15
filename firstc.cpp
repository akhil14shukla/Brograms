#include <iostream>
#include <vector>
using namespace std;

vector<int> maxset(vector<int> &A)
{
    vector<long long> sum;
    vector<int> index;
    vector<int> size;
    int j = 0;
    sum.push_back(0);
    index.push_back(0);
    size.push_back(0);
    for (int i = 0; i <= A.size(); i++)
    {
        if (A[i] >= 0)
        {
            sum[j] = sum[j] + A[i];
            size[j] = size[j] + 1;
        }
        if (A[i] < 0)
        {
            j = j + 1;
            sum.push_back(0);
            index.push_back(i + 1);
            size.push_back(0);
        }
    }
    int i;
    long long max = sum[0];
    int k;
    vector<int> num; //ones with maximum sum
    for (i = 0; i < sum.size(); i++)
    {
        if (sum[i] >= max)
        {
            max = sum[i];
            k = i;
        }
    }
    for (i = 0; i < sum.size(); i++)
        if (sum[i] == max)
            num.push_back(i);
    if (num.size() == A.size() && max == 0)
    {
        return {};
        j = 0;
        max = 0;

        if (num.size() > 1)
        {
            vector<int> max_size;
            while (j < num.size())
            {
                if (size[num[j]] >= max)
                {
                    max = size[num[j]];
                }
                j++;
            }
            for (i = 0; i < num.size(); i++)
                if (size[num[i]] == max)
                {
                    vector<int> final;
                    for (k = 0; k < size[num[i]]; k++)
                        final.push_back(A[index[num[i]] + k]);
                    return final;
                }
        }
        else
        {
            vector<int> final;
            for (i = 0; i < size[num[0]]; i++)
            {
                final.push_back(A[index[num[0]] + i]);
                //    cout << final[i - 1] << " ";
            }
            return final;
        }
        return A;
    }

    int main()
    {
        vector<int> A;
        int n, i, m;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> m;
            A.push_back(m);
        }
        vector<int> f = maxset(A);
        for (i = 0; i < f.size(); i++)
            cout << f[i] << " ";
    }