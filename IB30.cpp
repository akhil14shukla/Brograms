#include <bits/stdc++.h>
using namespace std;

int dfs(unordered_map<string, bool> &s, vector<unordered_map<char, bool>> &store, string cur, int count, string &B, int lasti, int &final, int lim)
{
    int n = cur.size();
    if (cur == B)
    {
        final = min(count + 1, final);
        cout << final << endl;
        return 0;
    }
    if (count > lim + 1)
    {
        return 0;
    }
    string ru = cur;
    for (int j = 0; j < store.size(); j++)
    {
        if (j != lasti)
            for (auto i : store[j])
            {
                ru[j] = i.first;
                if (s.find(ru)!=s.end() && s[ru] == false)
                {
                    s[ru] = true;
                    dfs(s, store, ru, count + 1, B, j, final, lim);
                    s[ru] = false;
                }
                ru = cur;
            }
    }
    return 0;
}

int solve(string A, string B, vector<string> &C) {
    unordered_map<string, bool> s;
    int n = A.size();
    vector<unordered_map<char, bool>> store(n);
    for (int i = 0; i < C.size(); i++)
    {
        s[C[i]] = false;
        for (int j = 0; j < n; j++)
        {
            store[j][C[i][j]] = false;
        }
    }
    s[B] = false;
    for (int i = 0; i < n; i++)
    {
        store[i][A[i]] = false;
        store[i][B[i]] = false;
    }
    int final = INT_MAX;
    dfs(s, store, A, 0, B, -1, final, C.size());
    if(final == INT_MAX){
        return 0;
    }
    return final;
}


int solve2(string A, string B, vector<string> &C) {
    unordered_map<string, bool> s;
    int n = A.size();
    vector<unordered_map<char, bool>> store(n);
    for (int i = 0; i < C.size(); i++)
    {
        s[C[i]] = false;
        for (int j = 0; j < n; j++)
        {
            store[j][C[i][j]] = false;
        }
    }
    s[B] = false;
    for (int i = 0; i < n; i++)
    {
        store[i][A[i]] = false;
        store[i][B[i]] = false;
    }
    
    int final = 1e5;
    queue<pair<string,int>> q;
    q.push({A,0});
    while(!q.empty()){
        string cur = q.front().first;
        int cou = q.front().second;
        q.pop();
        for (int j = 0; j < store.size(); j++)
        {
                for (auto i : store[j])
                {
                    string ru = cur;
                    if(ru == B){
                        final = min(final,cou);
                        // cout<<final<<endl;
                    }
                    ru[j] = i.first;
                    if(ru == B){
                        final = min(final,cou);
                        // cout<<final<<endl;
                    }
                    if (s.find(ru)!=s.end() && s[ru] == false)
                    {
                        s[ru] = true;
                        s.erase(ru);
                        q.push({ru,cou+1});
                    }
                }
        }
    }
    return final+2;
}

int main()
{
    string A = "ymain";
    string B = "oecij";
    vector<string> C = { "ymann", "yycrj", "oecij", "ymcnj", "yzcrj", "yycij", "xecij", "yecij", "ymanj", "yzcnj", "ymain"};
    cout << solve2(A, B, C)<<endl;
}
