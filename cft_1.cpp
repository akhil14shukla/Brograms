#include <bits/stdc++.h>
using namespace std;

int dfs(unordered_map<int, vector<int>> &m, vector<bool> &check, int curr, vector<pair<int, int>> &final, int count)
{

    for (int j = 0; j < m[curr].size(); j++)
    {
        if (m[m[curr][j]].size() == 1 && !check[m[curr][j]])
        {
            final.push_back({m[curr][j], count + 1});
        }
        if (!check[m[curr][j]])
        {
            check[m[curr][j]] = true;
            dfs(m, check, m[curr][j], final, count + 1);
            check[m[curr][j]] = false;
        }
    }
    return 0;
}

int dfs_search(unordered_map<int, vector<int>> &m, vector<bool> &check, int curr, unordered_set<int> &target, vector<pair<int, int>> &final, int count)
{
    // if (m[curr].size() == 1)
    // {
    //     final.push_back({curr, count});
    // }
    for (int j = 0; j < m[curr].size(); j++)
    {
        if (target.find(m[curr][j]) != target.end() && !check[m[curr][j]])
        {
            final.push_back({m[curr][j], count + 1});
            continue;
        }
        if (!check[m[curr][j]])
        {
            check[m[curr][j]] = true;
            int a = dfs_search(m, check, m[curr][j], target, final, count + 1);
            if (!a)
            {
                return a;
            }
            check[m[curr][j]] = false;
        }
    }
    // return 0;
    return 0;
}

int main()
{
    fstream cin;
    cin.open("input1.txt");
    ofstream Out("output.txt");
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, Q;
    cin >> N >> Q;
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < N - 1; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        m[t1].push_back(t2);
        m[t2].push_back(t1);
    }
    vector<bool> check(N, false);
    vector<vector<pair<int, int>>> finally(N + 1);
    for (int i = 1; i <= N; i++)
    {
        vector<bool> check(N, false);
        if (m[i].size() == 1)
        {
            check[i] = true;
            vector<pair<int, int>> final;
            dfs(m, check, i, final, 0);
            finally[i] = final;
        }
    }
    vector<int> leaves(N + 1, -1);
    for (int i = 1; i <= N; i++)
    {
        if (m[i].size() == 1)
        {
            leaves[i] = 0;
        }
    }

    int max1 = 0;
    int l1 = 1, l2 = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < finally[i].size(); j++)
        {
            if (max1 < finally[i][j].second)
            {
                max1 = finally[i][j].second;
                l1 = i;
                l2 = finally[i][j].first;
            }
        }
    }

    // Assuming that original tree has even number of leaf nodes
    long sum = max1;
    leaves[l1] = leaves[l2] = 1;
    for (int i = 1; i <= N; i++)
    {
        if (leaves[i] == 0)
        {
            long max2 = INT_MAX;
            int l3 = i, l4 = i;
            for (int j = 0; j < finally[i].size(); j++)
            {
                if (max2 > finally[i][j].second && leaves[finally[i][j].first] == 0)
                {
                    max2 = finally[i][j].second;
                    l3 = i;
                    l4 = finally[i][j].first;
                }
            }
            leaves[l3] = leaves[l4] = 1;
            sum += max2;
        }
    }
    // cout << sum << endl;

    for (int i = 0; i < Q; i++)
    {
        int d;
        cin >> d;
        unordered_set<int> a;
        for (int j = 0; j < d; j++)
        {
            int t;
            cin >> t;
            a.insert(t);
        }
        // if(d%2 == 1){
        //     cout<<-1<<endl;
        // }
        long sumt = sum + d;

        int count = 0;
        for (auto j = a.begin(); j != a.end(); j++)
        {
            if (*j <= N && leaves[*j] == 1)
            {
                count++;
                // sumt += 1;
                a.erase(*j);
            }
        }
        if ((d - count) % 2 == 1)
        {
            Out << -1 << endl;
            continue;
        }
        for (auto j = a.begin(); j != a.end(); j++)
        {
            vector<pair<int, int>> subfinal;
            vector<bool> check(N + 1, false);
            check[*j] = true;
            dfs_search(m, check, *j, a, subfinal, 0);
            finally[*j] = subfinal;
            int min2 = INT_MAX;
            int l5 = *j, l6 = *j;
            for (int ll = 0; ll < finally[*j].size(); ll++)
            {

                if (min2 > finally[*j][ll].second && leaves[finally[*j][ll].first] == -1)
                {
                    min2 = finally[*j][ll].second;
                    l5 = *j;
                    l6 = finally[*j][ll].first;
                }
            }
            leaves[l5] = leaves[l6] = 1;
            a.erase(l5);
            a.erase(l6);
            sumt += min2;
        }
        Out << sumt << endl;
    }
    return 0;
}