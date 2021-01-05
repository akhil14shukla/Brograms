#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod int(1e9+7)
#define rep(i,n) for(int i = 0;i<n;i++)
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> a(n);
        a[0] = 1;
        unordered_set<int> s2;
        vector<int> s1;
        s1.push_back(1);
        s2.insert(1);
        for(int i = 1;i<n;i++){
            if(s[i]!=s[i-1]){
                // s1.insert(a[i]);
                a[i] = a[i-1];
                s2.insert(a[i]);
                s1.push_back(a[i]);
            }
            else if(s[i] == s[i-1] && s1.size()%2 == 0){
                a[i] = a[i-1]-1;
                s1.clear();
                s2.insert(a[i]);
                s1.push_back(a[i]);
            }
            else if(s[i] == s[i-1] && s1.size()%2 == 1){
                a[i] = a[i-1]+1;
                s1.clear();
                s2.insert(a[i]);
                s1.push_back(a[i]);
            }
            
        }
        cout<<s2.size()<<endl;
        rep(i,n){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}