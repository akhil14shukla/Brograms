#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s, p;
        cin >> s >> p;
        unordered_map<char, int> m;
        for (int i = 0; i < s.size(); i++)
        {
            m[s[i]]++;
        }
        for (int i = 0; i < p.size(); i++)
        {
            m[p[i]]--;
        }
        string final;
        for (auto i = m.begin(); i != m.end(); i++)
        {
            while (i->second != 0)
            {
                
                final.push_back(i->first);
                i->second--;
            }
        }
        sort(final.begin(), final.end());
        int flag = 1;
        for (int i = 0; i < final.size(); i++)
        {
            if (final[i] > p[0])
            {
                final.insert(i, p);
                flag = 0;
                break;
            }
        }
        if(flag){
            final = final + p;
        }
        // string real_final;
        // int i = 0, j = 0;
        // while (i < final.size() && j < p.size())
        // {
        //     if (final[i] <= p[j])
        //     {
        //         real_final.push_back(final[i]);
        //         i++;
        //     }
        //     else{
        //         real_final.push_back(p[j]);
        //         j++;
        //     }
        // }
        // if(i!=final.size()){
        //     while(i<final.size()){
        //         real_final.push_back(final[i]);
        //         i++;
        //     }
        // }
        // if(j!=p.size()){
        //     while(j<p.size()){
        //         real_final.push_back(p[j]);
        //         j++;
        //     }
        // }
        cout<<final<<endl;
    }
    return 0;
}
