#include <bits/stdc++.h>
#include <cassert>
using namespace std;
// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

vector<int> dp(1e8,0);
// int fibonacci_fast(int n) {
long long g(long long n) {
    for(int i = 1;i<=n;i++){
        if(i<5){
            dp[i] = 1+dp[i-1];
        }
        if(i>=5 && i<10)
        dp[i] = 1+min(dp[i-1],dp[i-5]);
        if(i>=10)
        dp[i] = 1+min(dp[i-1],min(dp[i-5],dp[i-10]));
    }
return dp[n];
}
// }


int main() {
    // int n = 0;
    // std::cin >> n;
    // std::cout << fibonacci_fast(n) << '\n';
    //test_solution();
    long long n = 0;
    cin>>n;
    cout<<g(n);
    //std::cout << fibonacci_fast(n) << '\n';
    return 0;
}