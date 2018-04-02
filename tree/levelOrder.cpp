/* 问题描述：
 * 二叉树的层次遍历，从上到下
 */
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
	int data;
	TreeNode *lchild;
	TreeNode *rchild;
	TreeNode(int x): data(x), lchild(NULL), rchild(NULL){}
};

void create_tree(TreeNode *&root){
	TreeNode *p1 = (TreeNode*)malloc(sizeof(TreeNode)); 
	p1->data = 1;
	root = p1;
	TreeNode *p2 = (TreeNode*)malloc(sizeof(TreeNode)); 
	TreeNode *p3 = (TreeNode*)malloc(sizeof(TreeNode)); 
	p2->data = 2;
	p3->data = 3;
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = NULL;
	p2->rchild = NULL;
	p3->lchild = NULL;
	p3->rchild = NULL;	
}

vector<vector<int> > levelOrder(TreeNode *root){
	vector<vector<int> > result;
	queue<TreeNode*> q;
	vector<int> level;
	int size;
	if(root == NULL) return result;
	q.push(root);
	while(!q.empty()){
		level.clear();
		size = q.size();
		for(int i=0;i<size;++i){
			TreeNode *p = q.front();
			q.pop();
			level.push_back(p->data);
			if(p->lchild){
				q.push(p->lchild);
			}
			if(p->rchild){
				q.push(p->rchild);
			}
		}
		result.push_back(level);
	}
	/* 若采用从下到上，只需要将从上到下的结果反转一遍就好了
	for(int m=0, n=result.size()-1;m<n;++m,--n)
	{
		swap(result[m],result[n]);
	}
	*/
	return result;	
}

int main(){
	TreeNode *root = NULL;
	create_tree(root);
	vector<vector<int> > result = levelOrder(root);
	for(int i=0;i<result.size();++i)
		for(int j=0;j<result[i].size();++j)
			cout<<result[i][j]<<" ";
	cout<<endl;
	return 0;
}
