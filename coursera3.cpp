#include <iostream>
#include <vector>
#define ll long long
using std::cin;
using std::cout;
using std::max;
using std::vector;

ll compute_min_refills(ll dist, ll tank, vector<ll> &stops)
{
  ll current = 0;
  ll num = 0;
  while (current < stops.size()-1)
  {
    int last = current;
    while (current < stops.size()-1 && stops[current + 1] - stops[last] <= tank)
    {
      current++;
    }
    if (current == last)
    {
      return -1;
    }
    if (current < stops.size()-1)
      num++;
  }
  return num;
}
int countRefill(ll N, ll K, ll M, vector<ll> compulsory) 
{ 
    ll count = 0; 
    ll i = 0; 
    ll distCovered = 0; 
  
    // While we complete the whole journey. 
    while (distCovered < N) { 
        // If must visited petrol pump lie 
        // between distCovered and distCovered+K. 
        if (i < M && compulsory[i] <= (distCovered + K)) { 
            // make last mustVisited as distCovered 
            distCovered = compulsory[i]; 
  
            // increment the index of compulsory visited. 
            i++; 
        } 
  
        // if no such must visited pump is 
        // there then increment distCovered by K. 
        else
            distCovered += K; 
  
        // Counting the number of refill. 
        if (distCovered < N) 
            count++; 
    } 
  
    return count; 
} 
int main()
{
  ll d = 0;
  cin >> d;
  ll m = 0;
  cin >> m;
  ll n = 0;
  cin >> n;

  vector<ll> stops(n+1);
stops[0] = 0;
  for (size_t i = 1; i <= n; ++i)
    cin >> stops.at(i);
  stops.push_back(d);
  cout << compute_min_refills(d, m, stops) << "\n";

  return 0;
}