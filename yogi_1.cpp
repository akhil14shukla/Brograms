#include <bits/stdc++.h>
using namespace std;
#define ll long long

void rec(const string &s, string curr, vector<bool> check) {
    for (int i = 0; i<s.size();i++) {
        if (check[i] == false) {
            curr.push_back(s[i]);
            check[i] = true;
            if (curr.size() == s.size()) {
                cout<<curr<<" ";
                return;
            }
            rec(s,curr,check);
            curr.pop_back();
            check[i] = false;
        }
    }
}

int main() {
    int t;
    cin>>t;
    while (t--) {
        string s;
        cin>>s;
        sort(s.begin(), s.end());
        vector<bool> check(s.size(), false);
        string curr;
        rec(s,curr,check);
        cout<<endl;

    }

    return 0;
}