#include <bits/stdc++.h>
#include <string>
using namespace std;

int ArrayChallenge(string strArr[], int arrLength)
{
  int max2 = 0;
  string c = strArr[0];
  string d = strArr[1];
  for (int i = 0; i < d.size(); i++)
  {
    int n = c.size();
    int j = i;
    string cur;
    for (j = i; d[j] != ','; j++)
    {
      cur.push_back(d[j]);
    }
    i = j;
    int dp[arrLength + 1][cur.size() + 1];
    memset(dp, 0, (c.size() + 1) * (cur.size() + 1) * sizeof(int));
    for (int l = 1; l <= n; l++)
    {
      for (int k = 1; k <= cur.size(); k++)
      {
        if (cur[k - 1] == c[l - 1])
        {
          dp[l][j] = max(dp[l - 1][j - 1], max(dp[l - 1][j], dp[l][j - 1])) + 1;
        }
        else
        {
          dp[l][j] = max(dp[l - 1][l - 1], max(dp[l - 1][j], dp[l][j - 1]));
        }
      }
    }
    if (max2 < dp[n][cur.size()])
    {
      max2 = dp[n][cur.size()];
    }
  }
  return c.size() - max2;
  // code goes here
  // return strArr[0];
}

int main(void)
{

  // keep this function call here
  /* Note: In C++ you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */

  string A[] = {"baseball", "a,all,b,ball,bas,base,cat,code,d,e,quit,z"};
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayChallenge(A, arrLength);
  return 0;
}