#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

void rec(vector<string> &f, string s, int A, set<string> &se, int count, int n){
    if(count == 0 && A == 0){
        if(se.find(s) == se.end() && s.size() == 2*n){
        se.insert(s);
        f.push_back(s);
        }
        return;
    }
    if(A>0){
    s.push_back('(');
    A--;
    count--;
    rec(f,s,A,se,count, n);
    }
    if(count< 0){
        while(count!=0){
            s.push_back(')');
            count++;
            rec(f,s,A,se,count,n);
        }
    }
}


vector<string> sis(int A) {
    int i = 0;
    vector<string> f;
    set<string> se;
    string s;
    int count = 0;
    rec(f,s,A,se,count,A);
    return f;
    
}


int main()
{
    /* vector<int> A = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> B = slidingMaximum(A, 3);
    for(int i = 0; i<B.size();i++){
        cout<<B[i]<<" ";
    }*/
    vector<string> A = sis(3);
 
    {
        rep(j, A.size())
        {
            cout << A[j] << " ";
        }
        cout << endl;
    }
    return 0;
}