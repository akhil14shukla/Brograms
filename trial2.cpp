#include<bits/stdc++.h>
using namespace std;
int main(){
double T = 950.00;
double del = 100;
while(del>0.01){
    double temp = T;
    T = double(28624913.13)*exp(double(-14933.73)/T);
    del = abs(T - temp);
}
cout<<T<<endl;
    return 0;
}