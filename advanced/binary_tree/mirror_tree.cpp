/*
* 输入一颗二叉树，输出该二叉树的镜像
*/
void mirrorRecursively(TreeNode* root) {
    if(!root) return;
    if(!root->lchild && !root->rchild) return;

    TreeNode* tmp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = tmp;

    if(root->lchild)
        mirrorRecursively(root->lchild);
    if(root->rchild)
        mirrorRecursively(root->rchild);
}