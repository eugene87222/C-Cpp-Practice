#include <bits/stdc++.h>
using namespace std;

class BST{
private:
	class node{
	public:
		int data;
		node *right,*left;
	};
	node *root;
	node *insert(int num,node *t){
		if(t==NULL){
			t=new node;
			t->data=num;
			t->left=t->right=NULL;
		}
		else if(num>t->data) t->right=insert(num,t->right);
		else if(num<t->data) t->left=insert(num,t->left);
		return t;
	}
	void inorder(node *t){
		if(t==NULL) return;
		inorder(t->left);
		cout<<t->data<<" ";
		inorder(t->right);
	}
	node *clear(node *t){
		if(t==NULL) return NULL;
		clear(t->left);
		clear(t->right);
		delete t;
		return NULL;
	}
public:
	BST(){root=NULL;}
	~BST(){root=clear(root);}
	void insert(int num){root=insert(num,root);}
	void print(){inorder(root); cout<<endl;}
};
int main(int argc, char const *argv[])
{
	BST tree;
	for(int i=0;i<50;i++)
		tree.insert(i);
	tree.print();
	return 0;
}