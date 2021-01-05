// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// int main() {
//     int t;
//     cin>>t;
//     while (t--) {
//         int n, m;
//         cin>>n>>m;
//         vector<ll> a(n), b(m);
//         for (int i = 0;i<n;i++) {
//             cin>>a[i];
//         }
//         for (int j = 0;j<m;j++) {
//             cin>>b[j];
//         }
//         int j = 0;
//         for (int i = 0;i<n;i++) {
//             if (a[i]<b[j]) {
//                 // j++;
//                 continue;
//             }
//             else {
//                 swap(a[i], b[j]);
//                 int k = j;
//                 while(k<m-1 && b[k]>b[k+1]){
//                     swap(b[k],b[k+1]);
//                     k++;
//                 }
//                 // j++;
//             }
//             if(j == m){
//                 break;
//             }
//         }
//         for(int i = 0;i<n;i++){
//             cout<<a[i]<<" ";
//         }
//         for(int i = 0;i<m;i++){
//             cout<<b[i]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool  comp(pair<int, int> *a, pair<int,int> *b){
    return a->first<b->first;
}
int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, m;
        cin>>n>>m;
        // vector<ll> a(n+m);
        set<int,greater<int>> s1;
        for (int i = 0;i<n+m;i++) {
            int t1;
            cin>>t1;
            s1.insert(t1);
        }
        // sort(a.begin(),a.end());
        for (auto i = s1.rbegin();i!=s1.rend();i++) {
            cout<<*i<<" ";
        }
        cout<<endl;
    }

    return 0;
}