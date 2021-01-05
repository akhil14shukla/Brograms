#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}



int rec(vector<int> &A, int n,int &count,int &start, int &end){

    if(n>end){
        return 0;
    }
    if(n>=start && isPrime(n) && n<=end){
        count++;
    }

    for(int i = 0;i<A.size();i++){
        int temp = n*10 + A[i];
        rec(A,temp, count, start, end);
    }
    return 0;
}

int main(){
    vector<int> A = {1,5,9};
    int start = 1;
    int end = 9;
    int count = 0;
    rec(A,0,count,start,end);
    cout<<count;


    return 0;
}