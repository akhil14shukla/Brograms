/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
#include <stdio.h>
#include <stdlib.h>
int *plusOne(int *A, int n1, int *len1)
{
    int i;
    int a = 1;
    len1 = (int*)malloc((n1+1)*sizeof(int));
    for(i = n1-1;i>=0;i--){
        len1[i] = a + A[i];
        if(len1[i] == 10){
            len1[i] = 0;
            a = 1;
        }
        else a = 0;
    //    printf("%d", A[i]);
    }
    return len1;
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int *len1;
    int *j = plusOne(A, n, len1);
    for (i = 0; i < n + 1; i++)
        printf("%d", j[i]);
}