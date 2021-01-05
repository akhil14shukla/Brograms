#include<bits/stdc++.h>
using namespace std;

int kthsmallest(const vector<int> &A, int B) {
    int target = A[0];
    int index = 1;
    for(int i = 1;i<A.size();i++){
        if(index<B){
            if(target<=A[i]){
                target = A[i];
                index++;
            }
            else{
                index++;
            }
        }
        else if(index == B){
            if(target>=A[i]){
                target = A[i];
            }
        }
    }
    return target;
}


int main(){
    vector<int> A = {8, 16, 80, 55, 32, 8, 38, 40, 65, 18, 15, 45, 50, 38, 54, 52, 23, 74, 81, 42, 28, 16, 66, 35, 91, 36, 44, 9, 85, 58, 59, 49, 75, 20, 87, 60, 17, 11, 39, 62, 20, 17, 46, 26, 81, 92 };

    cout<<kthsmallest(A,9);
    return 0;
}