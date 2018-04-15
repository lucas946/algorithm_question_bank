/* 二叉树的6种遍历方式
 * 前序、中序、后序以及各自的非递归实现方式
 */
#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *lchild;
	TreeNode *rchild;
};

void create_tree(TreeNode *&root){
	/*
	TreeNode *p1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode *p2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode *p3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode *p4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode *p5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode *p6 = (TreeNode*)malloc(sizeof(TreeNode));
	*/
	TreeNode *p1 = new TreeNode;
	TreeNode *p2 = new TreeNode;
	TreeNode *p3 = new TreeNode;
	TreeNode *p4 = new TreeNode;
	TreeNode *p5 = new TreeNode;
	TreeNode *p6 = new TreeNode;
	p1->data = 1;
	p2->data = 2;
	p3->data = 3;
	p4->data = 4;
	p5->data = 5;
	p6->data = 6;
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = p4;
	p2->rchild = p5;
	p3->lchild = p6;
	p4->lchild = NULL;
	p4->rchild = NULL;
	p5->lchild = NULL;
	p5->rchild = NULL;
	p6->lchild = NULL;
	p6->rchild = NULL;
	p3->rchild = NULL;
	root = p1;
}

void pre_order_traverse(TreeNode* root){
	if(root == NULL) return;
	cout<<root->data<<" ";
	pre_order_traverse(root->lchild);
	pre_order_traverse(root->rchild);
	delete root;
}

void in_order_traverse(TreeNode* root){
	if(root == NULL) return;
	in_order_traverse(root->lchild);
	cout<<root->data<<" ";
	in_order_traverse(root->rchild);
	delete root;
}

void post_order_traverse(TreeNode *root){
	if(root == NULL) return;
	post_order_traverse(root->lchild);
	post_order_traverse(root->rchild);
	cout<<root->data<<" ";
	delete root;
}

void non_recursive_pre(TreeNode* root){
	if(root == NULL)
		return;
	TreeNode *p = root;
	stack<TreeNode*> stk;
	while(p != NULL || !stk.empty()){
		while(p != NULL){
			cout<<p->data<<" ";
			stk.push(p);
			p = p->lchild;
		}
		if(!stk.empty()){
			p = stk.top();
			stk.pop();
			p = p->rchild;
		}
	}	
}

int main(){
	TreeNode* root = NULL;
	create_tree(root);
	pre_order_traverse(root);
	cout<<endl;
	in_order_traverse(root);
	cout<<endl;
	//post_order_traverse(root);
	//non_recursive_pre(root);
	//cout<<endl;
	return 0;
}
