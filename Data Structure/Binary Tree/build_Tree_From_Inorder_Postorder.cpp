#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
typedef vector<int>::iterator Iter;
TreeNode *buildBinaryTreeRecur(Iter istart,Iter iend,Iter pstart,Iter pend){
    if(istart==iend||pstart==pend)
        return NULL;
    int ival=*(pend-1);
    Iter itemp=find(istart,iend,ival);
    TreeNode *res=new TreeNode(ival);
    res->left=buildBinaryTreeRecur(istart,itemp,pstart,pstart+(itemp-istart));
    res->right=buildBinaryTreeRecur(itemp+1,iend,pstart+(itemp-istart),pend-1);
    return res;
}
TreeNode *buildTreeFromInorderPostorder(vector<int> &inorder,vector<int> &postorder){
    return buildBinaryTreeRecur(inorder.begin(),inorder.end(),postorder.begin(),postorder.end());
}
void preOrder(TreeNode *node){
    if(node==NULL) return;
    cout<<node->val<<endl;
    preOrder(node->left);
    preOrder(node->right);
}
void postOrder(TreeNode *node){
    if(node==NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout<<node->val<<endl;
}
int main(){
    vector<int> in={10,1,3,7,0,5,9,6,4,8,2};
    vector<int> post={10,1,7,5,0,6,9,3,8,2,4};
    vector<int> pre={4,3,1,10,9,0,7,5,6,2,8};
    preOrder(buildTreeFromInorderPostorder(in,post));
    return 0;
}