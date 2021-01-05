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
        vector<ll> a(n);
        rep(i, n) {
            cin>>a[i];
        }
        // sort(a.begin(), a.end());
        unordered_map<ll, unordered_set<ll>> m;
        rep(i, n) {
            for (ll j = i+1;j<n;j++) {
                if (m[a[i] + a[j]].find(i) == m[a[i] + a[j]].end() && m[a[i] + a[j]].find(j) == m[a[i] + a[j]].end()){
                    m[a[i] + a[j]].insert(i);
                    m[a[i] + a[j]].insert(j);
                }
            }
        }
        ll max1 = -1e9;
        for (auto m1 = m.begin();m1!=m.end();m1++) {
            ll si = m1->second.size()/2;
            if (max1 < si) {
                max1 = si;
            }
        }
        if(max1<0){
            max1 = 0;
        }
        cout<<max1<<endl;
    }
    return 0;
}