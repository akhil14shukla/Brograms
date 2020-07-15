#include <bits/stdc++.h>
#include <stack>
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int dec(string A)
{
    int f1 = 0;
    int f = 0;
    int n = A.size() - 1;
    while (n >= 0)
    {
        if (A[n] == '1')
        {
            f = 1;
        }
        else
        {
            f = 0;
        }
        f1 = f1 + f * pow(2, A.size() - 1 - n);
        n--;
    }
    return f1;
}

void rec(vector<int> &f, string s, int i, int n,int o, set<int> &se)
{

    int m = 0;
    if (i < n && o == 1)
    {
        s[i] = '0';
        rec(f, s, i + 1, n,o, se);
        o = !o;
        m = dec(s);
        if (se.find(m) == se.end())
        {
            f.push_back(m);
            se.insert(m);
        }
        s[i] = '1';
        rec(f, s, i + 1, n,o, se);
        m = dec(s);
        if (se.find(m) == se.end())
        {
            f.push_back(m);
            se.insert(m);
        }
    }
    else     if (i < n && o == 0)
    {
        s[i] = '1';
        rec(f, s, i + 1, n,!o, se);
        o = !o;
        m = dec(s);
        if (se.find(m) == se.end())
        {
            f.push_back(m);
            se.insert(m);
        }
        s[i] = '0';
        rec(f, s, i + 1, n,!o, se);
        o = !o;
        m = dec(s);
        if (se.find(m) == se.end())
        {
            f.push_back(m);
            se.insert(m);
        }
    }
}

vector<int> grayCode(int A)
{
    vector<int> f;
    string s;
    int n = A;
    while (n > 0)
    {
        s.push_back('1');
        n--;
    }
    set<int> se;
    int o = 1;
    rec(f, s, 0, A,o, se);

    return f;
}
int main()
{
    vector<int> A = grayCode(10);
    // rep(i, A.size())
    {
        cout << A.size() << endl;
    }
}