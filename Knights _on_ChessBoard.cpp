#include <bits/stdc++.h>
using namespace std;

void dfs(map<pair<int, int>, vector<pair<int, int>>> &m, vector<vector<bool>> &check, int C, int D, int count, int &E, int &F, vector<int> &final)
{
    int n = m[{C, D}].size();
    for (int i = 0; i < n - 1; i++)
    {
        if (m[{C, D}][i].first == E && m[{C, D}][i].second == F)
        {
            final.push_back(count + 1);
        }
        else
        {
            check[C][D] = true;
            if (check[m[{C, D}][i].first][m[{C, D}][i].second] == false)
                dfs(m, check, m[{C, D}][i].first, m[{C, D}][i].second, count + 1, E, F, final);
            check[C][D] = false;
        }
    }
}

int knight(int A, int B, int C, int D, int E, int F)
{
    vector<vector<bool>> check(A, vector<bool>(B, false));
    vector<vector<vector<pair<int, int>>>> m(A, vector<vector<pair<int, int>>>(B));
    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if (i - 2 >= 0)
            {
                if (j - 1 >= 0)
                {
                    m[i][j].push_back({i - 2, j - 1});
                }
                if (j + 1 < B)
                {
                    m[i][j].push_back({i - 2, j + 1});
                }
            }
            if (i + 2 < A)
            {
                if (j - 1 >= 0)
                {
                    m[i][j].push_back({i + 2, j - 1});
                }
                if (j + 1 < B)
                {
                    m[i][j].push_back({i + 2, j + 1});
                }
            }
            if (j - 2 >= 0)
            {
                if (i - 1 >= 0)
                {
                    m[i][j].push_back({i - 1, j - 2});
                }
                if (i + 1 < A)
                {
                    m[i][j].push_back({i + 1, j - 2});
                }
            }
            if (j + 2 < B)
            {
                if (i - 1 >= 0)
                {
                    m[i][j].push_back({i - 1, j + 2});
                }
                if (i + 1 < A)
                {
                    m[i][j].push_back({i + 1, j + 2});
                }
            }
        }
    }
    vector<int> final;
    int E1 = E - 1;
    int F1 = F - 1;
    //BFS
    vector<vector<bool>> vis(A, vector<bool>(B, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{C - 1, D - 1}, 0});
    vis[C - 1][D - 1] = true;
    int count = 0;
    int flag = 0;
    while (!q.empty())
    {
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int count = q.front().second;
        q.pop();
        for (int i = 0; i < m[curx][cury].size(); i++)
        {
            if (vis[m[curx][cury][i].first][m[curx][cury][i].second] == false)
            {
                vis[m[curx][cury][i].first][m[curx][cury][i].second] = true;
                q.push({{m[curx][cury][i].first, m[curx][cury][i].second}, count + 1});
            }
            if (m[curx][cury][i].first == E - 1 && m[curx][cury][i].second == F - 1)
            {
                return count + 1;
            }
        }
    }
    return -1;
}

int main()
{
    cout << knight(8, 8, 1, 1, 8, 8);
}