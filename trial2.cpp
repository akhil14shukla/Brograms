#include<iostream>
using namespace std;
int main(){
    int A = 8;
     int count = 0;
    for(int i = 0;i<32;i++){
        if((A&1) == 0){
            count++;
            A >>=1;
        }
        else{
            break;
        }
    }
    cout<<count;
    return 0;
}