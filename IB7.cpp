#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

void rec(vector<int> A, vector<int> s, int i, set<vector<int>> &se)
{
    int n = i;
    for(; n<A.size();){
        s.push_back(A[n]);
        if(se.find(s) == se.end()){
            se.insert(s);
        }
        /*else{
            s.pop_back();
        }*/
        rec(A,s,n+1,se);
        if(s.size()!=0)
        s.pop_back();
        n++;
    }
}

vector<vector<int>> Dup(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> f = {{}};
    set<vector<int>> se;
    vector<int> s;
    int j = 0;
    int i = j;
    // for(j = 0;j<A.size();j++){
    rec(A, s, j, se);
    // }
    for (auto k : se)
    {
        f.push_back(k);
    }
    return f;
}

int main()
{
    /* vector<int> A = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> B = slidingMaximum(A, 3);
    for(int i = 0; i<B.size();i++){
        cout<<B[i]<<" ";
    }*/
    vector<int> A = {6, 6, 3, 3, 6, 5};
    vector<vector<int>> B = Dup(A);
    rep(i, B.size())
    {
        rep(j, B[i].size())
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}