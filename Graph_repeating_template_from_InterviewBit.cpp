#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int> > &A) {
    queue<pair<int,int>> q;
    int max1 = 0;
    vector<vector<bool>> check(A.size(),vector<bool>(A[0].size(),false));
    for(int i1 = 0;i1<A.size();i1++){
        for(int j1 = 0;j1<A[0].size();j1++){
            if(A[i1][j1] == 1 && !check[i1][j1]){
                int count = 0;
                q.push({i1,j1});
                
                check[i1][j1] = true;
                count++;
                while(!q.empty()){
                    int i = q.front().first;
                    int j = q.front().second;
                    q.pop();
                    if(i+1<A.size() && A[i+1][j] == 1 && !check[i+1][j]){
                        count++;
                        check[i+1][j] = 1;
                        q.push({i+1,j});
                    }
                    if(i+1<A.size() && j+1<A[0].size() && A[i+1][j+1] == 1 && !check[i+1][j+1]){
                        count++;
                        check[i+1][j+1] = 1;
                        q.push({i+1,j+1});
                    }
                    if(i+1<A.size() && j-1>=0 && A[i+1][j-1] == 1 && !check[i+1][j-1]){
                        count++;
                        check[i+1][j-1] = 1;
                        q.push({i+1,j-1});
                    }
                    
                    if(j+1<A[0].size() && A[i][j+1] == 1 && !check[i][j+1]){
                        count++;
                        check[i][j+1] = 1;
                        q.push({i,j+1});
                    }
                    if(i-1>=0 && A[i-1][j] == 1 && !check[i-1][j]){
                        count++;
                        check[i-1][j] = 1;
                        q.push({i-1,j});
                    }
                    if(i-1>=0 && j+1<A[0].size() && A[i-1][j+1] == 1 && !check[i-1][j+1]){
                        count++;
                        check[i-1][j+1] = 1;
                        q.push({i-1,j+1});
                    }
                    if(i-1>= 0 && j-1>=0 && A[i-1][j-1] == 1 && !check[i-1][j-1]){
                        count++;
                        check[i-1][j-1] = 1;
                        q.push({i-1,j-1});
                    }
                    
                    if(j-1>=0 && A[i][j-1] == 1 && !check[i][j-1]){
                        count++;
                        check[i][j-1] = 1;
                        q.push({i,j-1});
                    }
                }
                max1 = max(max1, count);
            }
        }
    }
    return max1;
}
