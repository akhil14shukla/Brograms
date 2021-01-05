#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> dp ={ -1, 1, 2, 3, 4, 5 };
    vector<int> store ={ -1, 1, 2, 3, 4, 5 };
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        // cout<<store[n]<<endl;
        int i = 0;
        int count = 0;
        int flag = 1;
        if (n<=store.size()) {
            cout<<store[n]<<endl;
            continue;
        }
        while (i<dp.size()) {
            if (dp[i]!=-1) {
                count++;
            }
            if (count == n) {
                cout<<dp[i]<<endl;
                flag = 0;
                break;
            }
            i++;
        }
        if (flag) {
            while (count<n) {
                if ((i%2 == 0 && dp[i/2] != -1) || (i%3 == 0 && dp[i/3]!=-1) || (i%5 == 0 && dp[i/5]!=-1)) {
                    count++;
                    dp.push_back(i);
                    store.push_back(i);
                    i++;
                }
                else {
                    dp.push_back(-1);
                    i++;
                }
            }
            cout<<store[n]<<endl;
        }
    }
    return 0;
}