#include<bits/stdc++.h>
using namespace std;

int solve(int A, vector<vector<int> > &B) {
    unordered_map<int, vector<int>> m;
    for(int i = 0;i<B.size();i++){
        m[B[i][0]].push_back(B[i][1]);
        m[B[i][1]].push_back(B[i][0]);
    }
    vector<bool> check(A+1,false);
    queue<pair<int,int>> q;
    for(int i = 1;i<=A;i++){
        if(check[i] == false){
            q.push({i,i});
            check[i] = true;
            // int last = i;
            while(!q.empty()){
                int cur = q.front().first;
                int last = q.front().second;
                q.pop();
                for(int j = 0;j<m[cur].size();j++){
                    if(check[m[cur][j]] == true && m[cur][j]!=last){
                        return 1;
                    }
                    else if(check[m[cur][j]] == false && m[cur][j]!=last){
                        q.push({m[cur][j],cur});
                        check[m[cur][j]] = true;
                    }
                }
                // last = cur;
            }
        }
    }
    return 0;
}
