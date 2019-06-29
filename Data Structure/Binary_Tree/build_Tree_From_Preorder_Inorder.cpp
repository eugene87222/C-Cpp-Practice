#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};
typedef vector<int>::iterator Iter;
TreeNode *buildTreeRecur(Iter pstart,Iter pend,Iter istart,Iter iend){
    if(pstart==pend||istart==iend)
        return NULL;
    int ival=*pstart;
    Iter ipos=find(istart,iend,ival);
    TreeNode *res=new TreeNode(ival);
    res->left=buildTreeRecur(pstart+1,pstart+1+(ipos-istart),istart,ipos);
    res->right=buildTreeRecur(pstart+1+(ipos-istart),pend,ipos+1,iend);
    return res;
}
TreeNode *buildTreeFromPreorderInorder(vector<int> &preorder, vector<int> &inorder){
    return buildTreeRecur(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
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
    postOrder(buildTreeFromPreorderInorder(pre,in));
    return 0;
}
