int rec(TreeNode* A, TreeNode* B){
    if(A == NULL && B!=NULL || A == NULL && B== NULL){
        return 1;
    }
    if(A!=NULL && B==NULL){
        return -1;
    }
    int a1 = rec(A->left,B->left);
    if(a1 == -1){
        return -1;
    }
    int a2 = rec(A->right,B->right);
    if(a2 == -1){
        return -1;
    }
    return 1;
 }
 int count(TreeNode* A){
     if(A == NULL){
     return 0;
 }
 int a2 = 1 + count(A->left);
 int a3 = count(A->right);
 return a2 + a3;
 }
int Solution::cntMatrix(TreeNode* A, TreeNode* B) {
    int f =  rec(A,B);
    if(f == -1){
        return -1;
    }
    int final = count(B) - count(A);
    if(final<0){
        return -1;
    }
    return final;
    
    
    
}   