#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>> &tb, const set<int> &C, const int &N, int count,int node, string f, set<string> &final)
{
    if(count == N && C.find(node)!=C.end()){
        final.insert(f);
    }
    else if(count>N){
        return ;
    }
    for(int i = 0;i<tb.size();i++){
        if(tb[node][i] == 0){
            f.push_back('0');
            dfs(tb,C,N,count+1,i,f,final);
            f.pop_back();
        }
        else if(tb[node][i] == 1){
            f.push_back('1');
            dfs(tb,C,N,count+1,i,f,final);
            f.pop_back();
        }
    }
    return ;
}

int main()
{
    vector<int> A = {0, 2, 1};
    vector<int> B = {1, 0, 2};
    vector<int> C = {0};
    int D = 0;
    int N = 3;
    {
        vector<vector<int>> tb(A.size(), vector<int>(A.size(), -1));
        for (int i = 0; i < A.size(); i++)
        {
            tb[i][A[i]] = 0;
        }
        for (int i = 0; i < B.size(); i++)
        {
            tb[i][B[i]] = 1;
        }
        set<int> C1;
        for(int i = 0;i<C.size();i++){
            C1.insert(C[i]);
        }
        set<string> final;
        string f;
        dfs(tb,C1,N,0,0,f,final);
        for(auto it = final.begin();it!=final.end();it++){
            cout<<*it<<endl;
        }
    }
}