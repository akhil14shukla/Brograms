#include <iostream>
#define ll long long int
using namespace std;

void MatrixMultiply(ll m[][2],ll n[][2]){
    ll res[2][2];
    for(ll i=0;i<2;i++){
        for(ll j=0;j<2;j++){
            res[i][j]=0;
            for(ll k=0;k<2;k++){
                res[i][j]+=(m[i][k]*n[k][j])%1000000007;
                res[i][j]= res[i][j]%1000000007;
            }
        }
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)m[i][j]=res[i][j];
    }
}
void MatrixPower(ll m[][2],ll k){
    ll temp[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++)temp[i][j]=m[i][j];
    }
    if(k<=1)return;
    //if(k==2){MatrixMultiply(m,m);return;}
    MatrixPower(temp,k/2);
    MatrixMultiply(temp,temp);
    if(k%2!=0){MatrixMultiply(m,temp);return;}
     for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)m[i][j]=temp[i][j];
    }
    return;
}
int main()
{
    ll n;
    cin>>n;
    ll m[2][2]={{3,1},{1,3}};
    ll u=1,d=0;
    if(n==0){
        cout<<u<<", "<<d;
    return 0;
    }
    MatrixPower(m,n);
    u = m[0][0];
    d = m[1][0];
    cout<<u<<", "<<d;
    return 0;
}